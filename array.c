#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "array.h"


array*	array_Construct(uint size)
{
	array* new_arr = (array* )calloc(1, sizeof(array));
	new_arr->size = size;
	new_arr->data = (array_t* )calloc(new_arr->size, sizeof(array_t));
	
	return new_arr;
}
void	array_Destroy(array* a)
{
	free(a->data);
	free(a);
}

void 	array_Dump(array* a)
{
	for (int i = 0; i < a->size; i++)
		printf("%d ", a->data[i]);
	printf("\n");
}

void array_Swap(array* a, uint n1, uint n2)
{
	array_t tmp = a->data[n1];
	a->data[n1] = a->data[n2];
	a->data[n2] = tmp;
}

//~ void array_Sort(array* a, uint left, uint right)
//~ {
  //~ uint vip; // разрешающий элемент
  //~ uint l = left; //левая граница
  //~ uint r = right; // правая граница
  //~ vip = a->data[left];
  //~ while (left < right) // пока границы не сомкнутся
  //~ {
    //~ while ((a->data[right] >= vip) && (left < right))
      //~ right--; // сдвигаем правую границу пока элемент [right] больше [vip]
    //~ if (left != right) // если границы не сомкнулись
    //~ {
      //~ a->data[left] = a->data[right]; // перемещаем элемент [right] на место разрешающего
      //~ left++; // сдвигаем левую границу вправо 
    //~ }
    //~ while ((a->data[left] <= vip) && (left < right))
      //~ left++; // сдвигаем левую границу пока элемент [left] меньше [vip]
    //~ if (left != right) // если границы не сомкнулись
    //~ { 
      //~ a->data[right] = a->data[left]; // перемещаем элемент [left] на место [right]
      //~ right--; // сдвигаем правую границу вправо 
    //~ }
  //~ }
  //~ a->data[left] = vip; // ставим разрешающий элемент на место
  //~ vip = left;
  //~ left = l;
  //~ right = r;
  //~ if (left < vip) // Рекурсивно вызываем сортировку для левой и правой части массива
    //~ array_Sort(a, left, vip - 1);
  //~ if (right > vip)
    //~ array_Sort(a, vip + 1, right);
//~ }

void	array_Sort(array* a, uint left, uint right)
{
	uint l = left, r = right;
	uint vip = a->data[left];
	
	while (left < right)
	{
		while (a->data[right] >= vip && left < right) right--;
		if (left != right)
		{
			a->data[left] = a->data[right];
			left++;
		}
		while (a->data[left] <= vip && left < right) left++;
		if (left != right)
		{
			a->data[right] = a->data[left];
			right--;
		}
		
	}
	a->data[left] = vip;
	vip = left;
	left = l;
	right = r;
	
	if (left < vip) array_Sort(a, left, vip - 1);
	if (right > vip) array_Sort(a, vip + 1, right);
}

void array_Initialize(array* a, array_t a1, array_t a2)
{
	for (int i = 0; i < a->size; i++)
		a->data[i] = rand() % (a2 - a1 + 1) + a1;
}
