#include <cstdio>

int n;

class deck
{
private:
	struct node
	{
		int value;
		node* next;
	};
	node* now;

public:
	deck(int size)
	{
		node* head = new node;
		now = head;
		for(int i=1; i<=size; ++i)
		{
			now->next = new node;
			now = now->next;
			now->value = i;
		}
		now->next = head->next;
		delete head;
	}

	void erase()
	{
		node* target = now->next;
		now->next = now->next->next;
		delete target;
	}

	void next()
	{
		now = now->next;
	} 

	int get()
	{
		return now->value;
	}
};

int main()
{
	scanf("%d", &n);

	deck d(n);
	for(int i=0; i<n-1; ++i)
	{
		d.erase();
		d.next();
	}

	printf("%d", d.get());
	return 0;
}
