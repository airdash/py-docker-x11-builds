 /* May need to explicitly mention /usr/lib/libdl.so in LD_PRELOAD
 * (or could or should it be /lib/libdl-2.11.3.so ?), otherwise ...?
 *
 * Compile and build library:
	cc -shared -o XlibNoSHM.so XlibNoSHM.c
 * to be used with
 *   LD_PRELOAD='libdl.so ./XlibNoSHM.so' firefox
 */

#include <stdio.h>
#include <string.h>
#include <X11/Xlib.h>
#include <dlfcn.h>
#define LIBXLIB "libXext.so.6"

Bool XQueryExtension(Display* dpl, _Xconst char* name, int* major, int* event, int* error)
{
  static Bool (*original_XQueryExtension)(Display*, _Xconst char*, int*, int*, int*) = NULL;

  /* printf("Got XQueryExtension %s\n",name); */
  if (!strcmp(name, "MIT-SHM")) {
    /* printf("Returning False for XQueryExtension %s\n",name); */
    *major = 0;
    return False;
  }
  if (!original_XQueryExtension) {
    void *handle = dlopen(LIBXLIB, RTLD_LAZY);
    if (!handle) return False;
    original_XQueryExtension = dlsym(handle, "XQueryExtension");
    if (!original_XQueryExtension) return False;
  }
  /* printf("Doing original_XQueryExtension ...\n"); */
  return original_XQueryExtension(dpl, name, major, event, error);
}

char** XListExtensions(Display* dpl, int* nexts)
{
  static char** (*original_XListExtensions)(Display*, int*) = NULL;
  char** extNames;
  int i;

  /* printf("Got XListExtensions\n"); */
  if (!original_XListExtensions) {
    *nexts = 0;
    void *handle = dlopen(LIBXLIB, RTLD_LAZY);
    if (!handle) return NULL;
    original_XListExtensions = dlsym(handle, "XListExtensions");
    if (!original_XListExtensions) return NULL;
  }
  /* printf("Doing original_XListExtensions ...\n"); */
  extNames = original_XListExtensions(dpl, nexts);

  if (extNames && *nexts > 0) {
    for (i = 0; i < *nexts; ++i) {
      if (extNames[i] && !strcmp(extNames[i],"MIT-SHM")) {
        /* printf("Replacing MIT-SHM by No-... in XListExtensions output\n"); */
        (void)strncpy(extNames[i],"No-",3);
      }
    }
  }

  return extNames;
}

Bool XShmQueryExtension(Display* display)
{
  /* printf("Returning False for XShmQueryExtension\n",); */
  return False;
}

Bool XShmQueryVersion(Display *display, int *major, int *minor, Bool *pixmaps)
{
  /* printf("Returning False for XShmQueryVersion\n",); */
  return False;
}
