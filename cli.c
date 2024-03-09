#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>


// Version (to be replaced with import)
const char* ROSIE_VERSION = "2.0.0-jsa";

// Commands
const char* HELP = "help";
const char* VERSION = "version";
const char* CONFIG = "config";
const char* LIST = "list";
const char* GREP = "grep";
const char* MATCH = "match";
const char* REPL = "repl";
const char* TEST = "test";
const char* EXPAND = "expand";
const char* TRACE = "trace";
const char* BYTECODE = "bytecode";


void print_version() {
    printf("Rosie %s\n", ROSIE_VERSION);
}

void print_help_short() {
    printf(
        "Usage: rosie [--verbose] [--rpl <rpl>] [-f <file>] [--norcfile]\n"
        "[--rcfile <rcfile>] [--libpath <libpath>] [--colors <colors>]\n"
        "[--help] [<command>] ...\n"
        "\n"
    );
    print_version();
}


void print_help_long() {
    printf(
        "Options:\n"
        "   --verbose             Output additional messages\n"
        "   --rpl <rpl>           Inline RPL statements\n"
        "    -f <file>,           Load an RPL file\n"
        "   --file <file>\n"
        "   --norcfile            Skip initialization file\n"
        "   --rcfile <rcfile>     Initialization file to read\n"
        "   --libpath <libpath>   Directories to search for rpl modules\n"
        "   --colors <colors>     Color/pattern assignments for color output\n"
        "   --help                Show this help message and exit.\n"
        "\n"
        "Commands:\n"
        "   version               Print rosie version\n"
        "   help                  Print this help message\n"
        "   config                Print rosie configuration information\n"
        "   list                  List patterns, packages, and macros\n"
        "   grep                  In the style of Unix grep, match the pattern anywhere in each input line\n"
        "   match                 Match the given RPL pattern against the input\n"
        "   repl                  Start the read-eval-print loop for interactive pattern development and debugging\n"
        "   test                  Execute pattern tests written within the target rpl file(s)\n"
        "   expand                Expand an rpl expression to see the input to the rpl compiler\n"
        "   trace                 Match while tracing all steps (generates MUCH output)\n"
        "   bytecode              Compile the pattern argument, and output a human-readable bytecode listing\n"
        "\n"
    );
}


void print_help() {
    print_help_short();
    printf("\n"); 
    print_help_long();
}


int handle_command(char *command) {
    if (0 == strcmp(command, HELP)) {
        print_help();
    } else if (0 == strcmp(command, VERSION)) {
        print_version();
    } else if (0 == strcmp(command, CONFIG)) {
        printf("Command '%s' not yet implemented\n", command);
    } else if (0 == strcmp(command, LIST)) {
        printf("Command '%s' not yet implemented\n", command);
    } else if (0 == strcmp(command, GREP)) {
        printf("Command '%s' not yet implemented\n", command);
    } else if (0 == strcmp(command, MATCH)) {
        printf("Command '%s' not yet implemented\n", command);
    } else if (0 == strcmp(command, REPL)) {
        printf("Command '%s' not yet implemented\n", command);
    } else if (0 == strcmp(command, TEST)) {
        printf("Command '%s' not yet implemented\n", command);
    } else if (0 == strcmp(command, EXPAND)) {
        printf("Command '%s' not yet implemented\n", command);
    } else if (0 == strcmp(command, TRACE)) {
        printf("Command '%s' not yet implemented\n", command);
    } else if (0 == strcmp(command, BYTECODE)) {
        printf("Command '%s' not yet implemented\n", command);
    } else {
        printf("Usage error.  Unknown command '%s'.\n", command);
        printf("\n");
        print_help();
        exit(EXIT_FAILURE);
    }

    return 0;
}

int main(int argc, char **argv) {
    int opt;
    int digit_optind = 0;
    char *command = NULL;

    struct option long_options[] = {
        {"verbose", no_argument, 0, 'v'},
        {"rpl", required_argument, 0, 'r'},
        {"file", required_argument, 0, 'f'},
        {"norcfile", no_argument, 0, 'n'},
        {"rcfile", required_argument, 0, 'e'},
        {"libpath", required_argument, 0, 'l'},
        {"colors", required_argument, 0, 'c'},
        {"help", no_argument, 0, 'h'},
        {0, 0, 0, 0}
    };

    int option_index = 0;
    while ((opt = getopt_long(argc, argv, "vr:f:ne:l:c:h",
                   long_options, &option_index)) != -1) {
        switch (opt) {
            case 'v':
                printf("option -v/--verbose\n");
                break;
            case 'r':
                printf("option -r/--rpl with value '%s'\n", optarg);
                break;
            case 'f':
                printf("option -f/--file with value '%s'\n", optarg);
                break;
            case 'n':
                printf("option -n/--norcfile\n");
                break;
            case 'e':
                printf("option -e/--rcfile with value '%s'\n", optarg);
                break;
            case 'l':
                printf("option -l/--libpath with value '%s'\n", optarg);
                break;
            case 'c':
                printf("option -c/--colors with value '%s'\n", optarg);
                break;
            case 'h':
                print_help();
                exit(EXIT_SUCCESS);
            case '?':
                printf("\n");
                print_help();
                exit(EXIT_FAILURE);
            default:
                printf("?? getopt returned character code 0%o ??\n", opt);
        }
    }

    if (optind < argc) {
        if (optind + 1 < argc) {
            printf("Usage error: Too many commands provided. \n");
            while (optind < argc)
                printf("%s ", argv[optind++]);
            printf("\n");
            printf("\n");        
            print_help();
            exit(EXIT_FAILURE);
        } else {
            command = argv[optind];
        }
    } else {
        printf("Usage error: No <command> provided. \n");
        printf("\n");        
        print_help();
        exit(EXIT_FAILURE);
    }

    int result = handle_command(command);

    exit(EXIT_SUCCESS);
}