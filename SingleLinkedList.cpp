#include"pch.h"
#include<conio.h>
#include<stdio.h>

int nodeNum = 0;// Số node trong List

struct node
{
	int data;
	node *next;
}; 

struct List
{
	node * head;
	node * tail;
};

void Initualize(List &l)
{
	l.head = NULL;
	l.tail = NULL;
}

void AddHead(List &l, int x)// Thêm vào đầu danh sách
{
	node* new_ele = new node;
	if (new_ele == NULL)
		return;
	else
	{
		new_ele->data = x;
		new_ele->next = NULL;
	}
	if (l.head == NULL)
	{
		l.head = l.tail = new_ele;
		nodeNum++;
	}
	else
	{
		new_ele->next = l.head;
		l.head = new_ele;
		nodeNum++;
	}
}

void AddTail(List &l, int x)// Thêm cuối danh sách
{
	node* new_ele = new node;
	if (new_ele == NULL)
		return;
	else
	{
		new_ele->data = x;
		new_ele->next = NULL;
	}
	if (l.head == NULL)
	{
		l.head = l.tail = new_ele;
		nodeNum++;
	}
	else
	{
		node* p = l.head;
		while (p != NULL)
			p = p->next;
		p = new_ele;
		l.tail->next = p;
		l.tail = p;
		nodeNum++;
	}
}

void AddNode(List &l, int pos, int x)
{
	node* new_element = new node;
	int run = 1;
	if (pos < 1 || pos > nodeNum + 1)
		return;
	else if (pos == 1)//Thêm đầu List
	{
		AddHead(l, x);
	}
	else if (pos == nodeNum + 1)//Thêm cuối List
	{
		AddTail(l, x);
	}
	else// Thêm giữa List
	{
		node* p = l.head;
		while (run < pos - 1)// Cho con trỏ chạy đến ngay trước vị trí cần thêm
		{
			p = p->next;
			run++;
		}
		node* p1 = p->next;// Cho p1 là node next của p lúc đầu
		p->next = new_element;// Cập nhật node next của p là node mới thêm
		new_element->data = x;
		new_element->next = p1;// Cập nhật node next của node mới là p1
		nodeNum++;
	}
}

void DelHead(List &l)// Xóa phần tử đầu
{
	node* p = l.head;
	if(p==NULL)
		return;
	else if (nodeNum == 1)
	{
		l.head = NULL;
		l.tail = NULL;
		nodeNum = 0;
	}
	else if (p != NULL && nodeNum > 1)
	{
		node* p1 = l.head->next;
		l.head = p1;
		delete(p);
		nodeNum--;
	}
}

void DelTail(List &l)// Xóa phần tử cuối
{
	node* p = l.head;
	if (p == NULL)
		return;
	else if (nodeNum == 1)
	{
		l.head = NULL;
		l.tail = NULL;
		nodeNum = 0;
	}
	else if (p != NULL && nodeNum > 1)
	{
		for (int i = 1; i < nodeNum - 1; i++)
		{
			p = p->next;
		}
		node* p1 = l.tail;
		p->next = NULL;
		l.tail = p;
		delete(p1);
		nodeNum--;
	}
}

void DeleteData(List &l, int x)// Xóa theo data của node
{
	node* p = l.head;
	int n = 0;// Dùng để đếm số lần p duyệt List
	while (p != NULL)
	{
		if (p == l.head && p->data == x)// Dùng nếu x là node đầu
		{
			DelHead(l);
			p = l.head;// Sau khi xóa đưa con trỏ p về node đầu
			continue;// Và qua vòng lặp
		}
		else if (p->data == x)// p phát hiện x
		{
			node* p1 = p;// Xóa p
			node* p2 = p->next;
			p = l.head;
			for (int i = 1; i < n; i++)// Cho p duyệt từ đầu đến node ngay trước node chứa x
				p = p->next;
			p->next = p2;
			delete(p1);
			nodeNum--;
			continue;// Sau khi xóa thì qua vòng lặp
		}
		p = p->next;
		n++;
	}
}

void DeleteNode(List &l, int pos)// Xóa node theo chỉ số
{
	node* p = l.head;
	int run = 1;// Biến chạy
	if (pos > nodeNum || pos < 1)
		return;
	else if(pos == 1)// Xóa node đầu
	{
		DelHead(l);
	}
	else if (pos == nodeNum)// Xóa node cuối
	{
		DelTail(l);
	}
	else// Xóa node giữa
	{
		while (run < pos - 1)// Dừng ngay trước node cần xóa
		{
			p = p->next;
			run++;
		}
		node* p1 = p->next;
		node* p2 = p->next->next;
		p->next = p2;
		delete(p1);
		nodeNum--;
	}
}

void getValue(List &l, int pos)
{
	if (pos < 0 || pos > nodeNum)
		return;
	node* p = l.head;
	int run = 1;
	while (run < pos)
	{
		p = p->next;
		run++;
	}
	printf("\nValue get from node %d is %d", pos, p->data);
}

void searchNode(List &l, int x)
{
	node* p = l.head;
	int pos = 1;
	while (p!=NULL && p->data != x)// Duyệt List
	{
		if (p->data == x)// Nếu phát hiện x thì dừng hẳn vòng lặp
			return;
		p = p->next;
		pos++;
		if (pos > nodeNum)// Nếu số đếm lớn hơn số node nghĩa là không tìm thấy node
		{
			printf("\nNo value found.");
		}
	}
	if (pos <= nodeNum)
		printf("\nValue %d found at node %d", x, pos);
}

void Display(List l)// Hiện danh sách
{
	node* p = l.head;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	//printf("\n%d", nodeNum);
}

int main()
{
	List l;
	Initualize(l);
	AddHead(l, 50);
	AddHead(l, 40);
	AddHead(l, 30);
	AddHead(l, 10);
	AddNode(l, 2, 20);
	Display(l);
	searchNode(l, 50);
	printf("\n");
	//DeleteNode(l, 4);
	//Display(l);
	_getch();
}