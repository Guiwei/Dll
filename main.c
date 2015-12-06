#include <stdio.h>
#include <dlfcn.h>
#include "caculate.h"

#define DLL_FILE_NMAE "./libcac.so"

int main()
{
	void *handle;
	int (*func)(int, int);
	char *error;

	int a = 20;
	int b = 10;

	handle = dlopen(DLL_FILE_NMAE, RTLD_NOW);
	if (NULL == handle)
	{
		printf("Failed to open libaray %s error:%s\n", DLL_FILE_NMAE, dlerror());
		return -1;
	}

	func = dlsym(handle, "add");
	printf("%d + %d = %d\n", a, b, func(a, b));

	dlclose(handle);
	return 0;
}
