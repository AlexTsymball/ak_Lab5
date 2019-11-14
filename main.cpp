#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <string.h>

struct globalArgs_t {
  int noIndex;        /* -I option */
  char *langCode;        /* -l option */
  const char *outFileName;  /* -o option */
  int verbosity;        /* -v option */
} globalArgs;

static const char *optString = "Il::o:vh";

static const struct option longOpts[] = {
  { "no-index", no_argument, NULL, 'I' },
  { "language", required_argument, NULL, 'l' },
  { "output", required_argument, NULL, 'o' },
  { "verbose", no_argument, NULL, 'v' },
  { "help", no_argument, NULL, 'h' },
  { NULL, no_argument, NULL, 0 }
};


int main( int argc, char *argv[] )
{
  int opt = 0;
  int longIndex = 0;
  int I = 0;
  int l = 0;
  int o = 0;
  int v = 0;
  int h = 0;
  
  /* Initialize globalArgs before we get to work. */
  globalArgs.noIndex = 0;    /* false */
  globalArgs.langCode = NULL;
  globalArgs.outFileName = NULL;
  globalArgs.verbosity = 0;
 
  opt = getopt_long( argc, argv, optString, longOpts, &longIndex );
  while( opt != -1 ) {
    switch( opt ) {
      case 'I':
       if(I==0){
	      printf("found argumente \"no-Index\"\n");
	      I++;
       }
        break;
        
      case 'l':
	if(l==0){
       printf("found argumente \"language = %s\"\n",optarg);
       l++;
	}
        break;
        
      case 'o':
	if(o==0){
       printf("found argumente \"output = %s\"\n",optarg);
       o++;
	}
        break;
        
      case 'v':
	if(v==0){
       printf("found argumente \"verbose\"\n");
       o++;
	}
        break;
        
      case 'h':
	if(h==0){
       printf("found argumente \"help\"\n");
       h++;
	}
       break;
	
      case '?':
        break;
        
      default:
        /* You won't actually get here. */
        break;
    }
    
    opt = getopt_long( argc, argv, optString, longOpts, &longIndex );
  }
  
  return EXIT_SUCCESS;
}
