#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/ioctl.h>

int main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <hex_color>\n", argv[0]);
        fprintf(stderr, "Example: %s 0xFF0000 (red)\n", argv[0]);
        return 1;
    }

    uint32_t color = strtoul(argv[1], NULL, 0);  // 0xRRGGBB
    const char *fb_path = (argc >= 3) ? argv[2] : "/dev/fb0";

    printf("Opening framebuffer: %s\n", fb_path);

    int fd = open(fb_path, O_RDWR);
    if (fd < 0) {
        perror("open framebuffer");
        return 1;
    }

    // --- Hardcode known display resolution for Pico i.MX8MM ---
    int width = 720;
    int height = 1280;
    int bytes_per_pixel = 4; // Assume ARGB8888

    long screensize = width * height * bytes_per_pixel;

    printf("Mapping %dx%d framebuffer (%ld bytes)\n", width, height, screensize);

    uint32_t *fbmem = mmap(0, screensize, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (fbmem == MAP_FAILED) {
        perror("mmap framebuffer");
        close(fd);
        return 1;
    }

    printf("Filling screen with color 0x%06X...\n", color);

    for (long i = 0; i < (screensize / 4); i++) {
        fbmem[i] = color;  // Each pixel: 0xRRGGBB
    }

    munmap(fbmem, screensize);
    close(fd);

    printf("Done.\n");
    return 0;
}

