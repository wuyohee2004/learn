#pragma once

#include <types.h>

#define O_RDONLY   1
#define O_WRONLY   2
#define O_RDWR     3

struct stat {
	size_t st_size;
};

int GAPI open(const char *name, int flags, ...);

int GAPI close(int fd);

ssize_t GAPI read(int fd, void *buff, size_t count);

ssize_t GAPI write(int fd, const void *buff, size_t count);

int GAPI ioctl(int fd, int cmd, ...);

#define SEEK_SET   1
#define SEEK_END   2
#define SEEK_CUR   3

loff_t GAPI lseek(int fd, loff_t offset, int whence);

int GAPI fstat(int fd, struct stat *stat);

int GAPI mount(const char *, const char *, const char *, unsigned long);

int GAPI umount(const char *mnt);
