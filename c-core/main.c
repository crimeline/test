#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>

int discovery_options(int argc, char** argv, int *show_help, int *show_version,char *input)
{
    int ret = 0;
    
    static struct option long_options[] = {
        {"help", no_argument, 0, 'h'},
        {"version", no_argument, 0, 'v'},
        {"arga", required_argument , 0, 'a'},
        {"argb", required_argument , 0, 'b'},
        {0, 0, 0, 0}
    };
    
    int opt = 0;
    int option_index = 0;
    while((opt = getopt_long(argc, argv, "hva:b:", long_options, &option_index)) != -1){
        switch(opt){
        case 'h':
                *show_help = 1;
                break;
        case 'v':
                *show_version = 1;
                break;
        case 'a':
                strcpy(input, optarg);
                break;
        case 'b':
                strcpy(input, optarg);
                break;
            default:
                *show_help = 1;
                break;
        }
    }
    // check values

    return ret;
}

void help(char** argv){
    printf("%s, Copyright (c) 2013-2015 BuguTian\n", argv[0]);
    printf(""
        "Usage: %s <Options> <-a REQUEST>\n"
        "-h no arg,mean help\n"
        "-v no arg,mean version\n"
        "-a arga\n"
        "-b argb\n",
        argv[0]);
        
    exit(0);
}
void version()
{
    printf("V1.1.1\n");
    exit(0);
}

int main(int argc, char** argv){
    int ret = 0;
    int show_help = 0;
    int show_version = 0;
    char input[128]="";
    if((ret = discovery_options(argc, argv, &show_help, &show_version, input))){
        printf("discovery options failed. ret=%d", ret);
        return ret;
    }
    if(show_help){
        help(argv);
    }
    if(show_version){
        version();
    }
    printf("[%s] running...\n", input);
    return 0;
}

