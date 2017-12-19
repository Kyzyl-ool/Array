#include "array.h"

int main()
{
	array* a = array_Construct(100);
	array_Initialize(a, 0, 100);
	
	
	array_Dump(a);
	array_Sort(a, 0, a->size - 1);
	array_Dump(a);
	
	array_Destroy(a);
	return 0;
}
