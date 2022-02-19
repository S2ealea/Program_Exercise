#include <stdio.h>
#include <stdlib.h>

 int main(int argc, char const *argv[])
{
	


	// Define linked-stack node struct
	typedef struct stack_node {
		struct stack_node *next;
		void* data;
	} stack_node;


	// Define the struct of the stack
	typedef struct stack
	{
		struct stack_node* top;
		int length ;				// Stack height		
	} stack ;


	// Create the stack
	stack* stack_create ()
	{
		stack* stack = (struct stack*)malloc(sizeof(struct stack));

		if (stack == NULL ) return NULL;

		//Init
		stack->top = NULL;
		stack->length = 0;

		return stack;
	}




	// Push into the stack
	stack* stack_push(stack* stack, void* data)
	{

		// Create a node
		stack_node* node = (stack_node*)malloc(sizeof(stack_node));
		if ( node == NULL ) return NULL;

		node->data = data;

		//Push 
		node->next = stack->top;
		stack->top = node;

		stack->length++;

		return stack;
	}


	// PoP out the stack
	void* stack_pop (stack* stack)
	{
		//Store the stack top temp
		stack_node* curr = stack->top;
		if ( curr == NULL ) return NULL;
		void* data = curr->data;

		// Pop the top
		stack->top = stack->top->next;
		free(curr);
		stack->length--;

		return data;
		}




		//Empty the stack
		void stack_empty( stack* stack)
		{
			int length = stack->length;
			stack_node *curr,*next;

			curr = stack->top;

			while( length-- )
			{
				next = curr->next;
				free(curr);
				curr = next;
			}

			stack->length = 0;
			stack->top = NULL;
		}





		//Destory the stack
		void stack_release(stack* stack)
		{
			stack_empty(stack);
			free(stack);
		}




		// Test code
	char a = 'a';
    char b = 'b';
    char c = 'c';

    /* 创建一个栈 */
    stack *s = stack_create();

    printf("%p\n", stack_pop(s));

    /* 压栈 */
    stack_push(s, &a);
    stack_push(s, &b);
    stack_push(s, &c);
    /* 出栈 */
    while (s->length > 0)
    {
        printf("%c\n", *(char *)stack_pop(s));
    }

    /* 压栈 */
    stack_push(s, &a);
    stack_empty(s);
    printf("%p\n", stack_pop(s));

    /* 释放栈 */
    stack_release(s);
    return 0;



	}
