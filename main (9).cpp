#include <iostream>

using namespace std;

struct node
{
  int data;
  node *link;
};

class Stack
{
private:

  node * top;

public:

  Stack ()
  {
    top = NULL;
  }

  void pushValue (int i);
  int popValue ();
  void SearchValue ();
  void tukarnilai();
  void sorting ();

  ~Stack ()
  {
    if (top == NULL)
      return;
    node *temp;
    while (top != NULL)
      {
	temp = top;
	top = top->link;
	delete temp;
      }
  }
};

void Stack::pushValue (int i)
{
  node *temp;
  temp = new node;
  temp->data = i;
  temp->link = NULL;
  if (top == NULL)
    {
      top = temp;
    }
  else
    {
      temp->link = top;
      top = temp;
    }
}

int Stack::popValue ()
{
  node *temp;
  int n;
  if (top == NULL)
    {
      cout << "Kosong" << endl;
      return NULL;
    }
  else
    {
      n = top->data;
      temp = top;
      top = top->link;
      delete temp;
    }
  return n;
}

void Stack::SearchValue ()
{
  struct node *temp;
  int x;
  int pos = 1;
  temp = new node;
  temp->data = x;
  temp->link = NULL;
  while (top != NULL)
    {
      if (temp->data == x)
	{
	  printf ("%d ditemukan di pos %d\n", x, pos);
	  return;
	}
      top = temp->link;
      pos++;
    }
  printf ("%d tidak ditemukan di list\n", x);
}

void Stack::sorting ()
{
  struct node *temp;
  int y = 0;
  temp = top;
  while (temp->data != NULL)
    {
      if (temp->data < temp->link->data)
	{
	  cout<<(temp, temp->link);
	  y = 1;
	}
    temp = temp->link;
    }
    top = temp;
}

int
main ()
{
  Stack s;
  struct node *start = NULL;
  int temp;
  int x;
  int pilihan;
  while (1)
    {
      cout << "Jasa Laundry" << endl;
      cout << "1.Tambah Baju" << endl;
      cout << "2.Hapus Baju" << endl;
      cout << "3.Cari baju" << endl;
      cout << "4.Tukar Urutan Baju" << endl;
      cout << "5.Sorting Menurut Ukuran Baju" << endl;
      cout << "Pilih: ";
      cin >> pilihan;
      switch (pilihan)
	{
	case 1:
	  cout << "Masukkan Ukuran Baju :" << endl;
	  cin >> temp;
	  s.pushValue (temp);
	  break;
	case 2:
	  temp = s.popValue ();
	  cout << temp << "Sudah dihapus" << endl;
	  break;
	case 3:
	  cout << "Baju yang dicari : " << endl;
	  scanf ("%d", &x);
	  s.SearchValue ();
	  break;
	case 4:
	  break;
	case 5:
	s.sorting();
	  break;
	  return 0;
	}

    }

  return 0;
}