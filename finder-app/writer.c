#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[])
{
    openlog("writer", LOG_PID, LOG_USER);

    if (argc != 3) {
        syslog(LOG_ERR, "Usage: %s <file> <string>", argv[0]);
        closelog();
        return 1;
    }

    const char *file = argv[1];
    const char *string = argv[2];

    syslog(LOG_DEBUG, "Writing %s to %s", string, file);

    FILE *fp = fopen(file, "w");
    if (!fp) {
        syslog(LOG_ERR, "Error opening file %s: %s", file, strerror(errno));
        closelog();
        return 1;
    }

    if (fprintf(fp, "%s", string) < 0) {
        syslog(LOG_ERR, "Error writing to file %s: %s", file, strerror(errno));
        fclose(fp);
        closelog();
        return 1;
    }

    fclose(fp);
    closelog();
    return 0;
}
