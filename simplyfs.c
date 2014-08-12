#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <fuse.h>

static const char *file_path = "/some_file.txt";
static const char file_content[] = "SimplyFs!\n";
static const size_t file_size = sizeof(file_content)/sizeof(char) - 1;

static int sfs_getattr(const char *path, struct stat *stbuf) {
    memset(stbuf, 0, sizeof(struct stat));

    if(strcmp(path, "/") == 0) {
        // handle the directory case - permissions to rwx, rw, rw
        stbuf -> st_mode = S_IFDIR | 0755;
        stbuf -> st_nlink = 3;
    }
    else if (strcmp(path, file_path) == 0) {
        // handle the regular case - permission to r, r, r
        stbuf -> st_mode = S_IFREG | 0444;
        stbuf -> st_nlink = 1;
        stbuf -> st_size = file_size;
    }
    else {
        // can't find the entry
        return -ENOENT;
    }
    return 0;
}

static struct fuse_operations sfs_filesystem_operations = {
    .getattr = sfs_getattr
};

int main(int argc, char **argv)
{
    return fuse_main(argc, argv, &sfs_filesystem_operations, NULL);
}

