typedef unsigned int uint;
typedef uint array_t;

typedef struct array
{
	array_t* data;
	uint size;
} array;

array*	array_Construct(uint size);
void	array_Destroy(array* a);
void array_Initialize(array* a, array_t a1, array_t a2);


void 	array_Dump(array* a);

//~ void	array_Sort(array* a, uint left, uint right);
void array_Sort(array* a, uint left, uint right);
void 	array_Swap(array* a, uint n1, uint n2);
