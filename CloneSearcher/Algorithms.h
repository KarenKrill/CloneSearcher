#pragma once
#include "stdafx.h"

namespace SAL
{
	#define MAX_SIZE (unsigned int)-1
	#define RED true
	#define BLACK false
	template<typename Key, typename Data>
	struct RBTreeNode
		{
			RBTreeNode<Key, Data> *parent;
			RBTreeNode<Key, Data> *left;
			RBTreeNode<Key, Data> *right;
			bool color; //true - red, false - black
			Key key;
			Data data;
			RBTreeNode(){ parent = left = right = NULL; color = false; }
		};
	template<typename Key, typename Data>
	class RedBlackTree
		{
			RBTreeNode<Key, Data> *root;
			unsigned int size;
		public:
			RedBlackTree(){root=NULL; size=0;}
			~RedBlackTree(){Clear();}
			RBTreeNode<Key, Data> *GetRoot(){ return root; }
			unsigned int GetSize(){return size;}
			void LeftRotate(RBTreeNode<Key, Data> *x)
			{
				if(!x) return;
				RBTreeNode<Key, Data> *y=x->right;
				if(y)
				{
					x->right=y->left;
					if(y->left) y->left->parent=x;
					y->parent=x->parent;
					y->left=x;
				}
				if(x->parent)
				{
					if(x==x->parent->left) x->parent->left=y;
					else x->parent->right=y;
				}
				else root=y;
				x->parent=y;
			}
			void RightRotate(RBTreeNode<Key, Data> *x)
			{
				if(!x) return;
				RBTreeNode<Key, Data> *y = x->left;
				if(y)
				{
					x->left=y->right;
					if(y->right) y->right->parent=x;
					y->parent=x->parent;
					y->right=x;
				}
				if(x->parent)
				{
					if(x==x->parent->left) x->parent->left=y;
					else x->parent->right=y;
				}
				else root=y;
				x->parent=y;
			}
			RBTreeNode<Key, Data>* Min(RBTreeNode<Key, Data> *x)
			{
				if(!root) return NULL;
				RBTreeNode<Key, Data> *parent=NULL, *current = x;
				if(x==NULL) current=root;
				while(current)
				{
					parent=current;
					current=current->left;
				}
				return parent;
			}
			RBTreeNode<Key, Data>* Max(RBTreeNode<Key, Data> *x)
			{
				if(!root) return NULL;
				RBTreeNode<Key, Data> *parent, *current = x;
				if(x==NULL) current=root;
				while(current)
				{
					parent=current;
					current=current->right;
				}
				return parent;
			}
			RBTreeNode<Key, Data>* Next(RBTreeNode<Key, Data> *x)
			{
				if(!x) return NULL;
				if(x->right) return Min(x->right);
				RBTreeNode<Key, Data> *parent = x->parent, *current = x;
				while(parent&&current!=parent->left)
				{
					current=parent;
					parent=current->parent;
				}
				return parent;
			}
			RBTreeNode<Key, Data>* Prev(RBTreeNode<Key, Data> *x)
			{
				if(!x) return NULL;
				if(x->left) return Max(x->left);
				RBTreeNode<Key, Data> *parent = x->parent, *current = x;
				while(parent&&current!=parent->right)
				{
					current=parent;
					parent=current->parent;
				}
				return parent;
			}
			void InsertFixup(RBTreeNode<Key, Data> *x)
			{
				RBTreeNode<Key, Data> *y;
				while(x!=root&&x->parent->color==RED)
				{
					if(x->parent==x->parent->parent->left)
					{
						y=x->parent->parent->right;
						if(y&&y->color==RED)
						{
							x->parent->color=BLACK;
							y->color=BLACK;
							x->parent->parent->color=RED;
							x=x->parent->parent;
						}
						else
						{
							if(x==x->parent->right)
							{
								x=x->parent;
								LeftRotate(x);
							}
							x->parent->color=BLACK;
							x->parent->parent->color=RED;
							RightRotate(x->parent->parent);
						}
					}
					else
					{
						y=x->parent->parent->left;
						if(y&&y->color==RED)
						{
							x->parent->color=BLACK;
							y->color=BLACK;
							x->parent->parent->color=RED;
							x=x->parent->parent;
						}
						else
						{
							if(x==x->parent->left)
							{
								x=x->parent;
								RightRotate(x);
							}
							x->parent->color=BLACK;
							x->parent->parent->color=RED;
							LeftRotate(x->parent->parent);
						}
					}
				}
				root->color=BLACK;
			}
			RBTreeNode<Key, Data>* Insert(Key key, Data data)
			{
				if(size==MAX_SIZE) return NULL;
				RBTreeNode<Key, Data> *current, *parent, *x;
				current=root; parent=NULL;
				while(current!=NULL)
				{
					if(key==current->key) return current;
					parent=current;
					current=(key<current->key)?current->left:current->right;
				}
				x = new RBTreeNode<Key, Data>;
				x->data=data;
				x->key = key;
				x->parent=parent;
				x->left=NULL;
				x->right=NULL;
				x->color=RED;
				if(parent)
				{
					if(key<parent->key) parent->left=x;
					else parent->right=x;
				}
				else root=x;
				size++;
				InsertFixup(x);
				return x;
			}
			void DeleteFixup(RBTreeNode<Key, Data> *x)
			{
				if(!x) return;
				while(x!=root&&x->color==BLACK)
				{
					if(x==x->parent->left)
					{
						RBTreeNode<Key, Data> *w = x->parent->right;
						if(w->color==RED)
						{
							w->color=BLACK;
							x->parent->color=RED;
							LeftRotate(x->parent);
							w=x->parent->right;
						}
						if(w->left->color==BLACK&&w->right->color==BLACK)
						{
							w->color=RED;
							x=x->parent;
						}
						else
						{
							if(w->right->color==BLACK)
							{
								w->left->color=BLACK;
								w->color=RED;
								RightRotate(w);
								w=x->parent->right;
							}
							w->color=x->parent->color;
							x->parent->color=BLACK;
							w->right->color=BLACK;
							LeftRotate(x->parent);
							x=root;
						}
					}
					else
					{
						RBTreeNode<Key, Data> *w = x->parent->left;
						if(w->color==RED)
						{
							w->color=BLACK;
							x->parent->color=RED;
							RightRotate(x->parent);
							w=x->parent->left;
						}
						if(w->right->color==BLACK&&w->left->color==BLACK)
						{
							w->color=RED;
							x=x->parent;
						}
						else
						{
							if(w->left->color==BLACK)
							{
								w->right->color=BLACK;
								w->color=RED;
								LeftRotate(w);
								w=x->parent->left;
							}
							w->color=x->parent->color;
							x->parent->color=BLACK;
							w->left->color=BLACK;
							RightRotate(x->parent);
							x=root;
						}
					}
				}
				if(x) x->color=BLACK;
			}
			void DeleteNode(RBTreeNode<Key, Data> *z)
			{
				if(size==0||!z) return;
				RBTreeNode<Key, Data> *x, *y;
				if(!z->left||!z->right) 
				{
					if(z->left)	x=z->left;
					else x=z->right;
					y=z;
					if(x) x->parent=y->parent;
					if(y->parent)
					{
						if(y==y->parent->left) y->parent->left=x;
						else y->parent->right=x;
					}
					else root=x;
					size--;
					if(x&&x->color==RED/*&&y->color==BLACK*/) DeleteFixup(x);
					delete z;
					z=0;
				}
				else 
				{
					y=Next(z);
					z->key = y->key;
					z->data = y->data;
					DeleteNode(y);
				}
			}
			RBTreeNode<Key, Data>* Search(Key key)
			{
				RBTreeNode<Key, Data> *current = root;
				while(current!=NULL)
				{
					if(key==current->key) return current;
					current=(key<current->key)?current->left:current->right;
				}
				return NULL;
			}
			bool Remove(Key key)
			{
				if(size==0) return false;
				RBTreeNode<Key, Data> *temp;
				if((temp=Search(key))==NULL) return false;
				DeleteNode(temp);
				temp=0;
				return true;
			}
			void Clear()
			{
				while (size) { DeleteNode(root); }
				return;
			}
		};

	template<typename T> struct ListNode
	{
		T key;
		ListNode<T> *next;
		ListNode(){ next = NULL; }
	};
	template<typename T> class List
		{
			ListNode<T> *head, *tail, *curr;
			uint size;
			bool (*LessRelation)(T a, T b);
			static bool DefaultLessRelation(T a, T b){ return (a < b); }
		public:
			List(){ head = curr = tail = NULL; size = 0; LessRelation = &DefaultLessRelation; }
			~List(){ Clear(); }
			uint Size() const { return size; }
			void PushBack(T key)
			{
				ListNode<T> *temp;
				temp = new ListNode<T>;
				temp->key = key; temp->next = NULL;
				if (tail) tail->next = temp;
				else head = temp;
				curr = tail = temp;
				size++;
			}
			void PushFront(T key)
			{
				ListNode<T> *temp;
				temp = head;
				head = new ListNode<T>;
				head->key = key; head->next = temp;
				if (!temp) tail = head;
				curr = head;
				size++;
			}
			void Push(T key){ PushBack(key); }
			void Pop()
			{
				ListNode<T> *temp;
				if (head)
				{
					temp = head->next;
					delete head;
					head = curr = temp;
					size--;
				}
				if (!head) tail = NULL;
			}
			bool Search(T key)
			{
				SetCur();
				for (uint i = 0; i<size; i++)
				{
					if (curr->key == key) return true;
					else Next();
				}
				return false;
			}
			bool Remove(T key)
			{
				if (!head) return false;
				ListNode<T> *temp;
				if (head->key == key)
				{
					temp = head->next;
					delete head;
					head = curr = temp;
					if (!head) tail = NULL;
					size--;
					return true;
				}
				curr = head;
				while (curr->next&&curr->next->key != key) curr = curr->next;
				if (!curr->next) return false;
				temp = curr->next->next;
				delete curr->next;
				curr->next = temp;
				size--;
				if (!temp) tail = curr;
				return true;
			}
			bool Remove(uint i)
			{
				if (i >= size || size == 0) return false;
				ListNode<T> *temp;
				if (i == 0)
				{
					temp = head->next;
					delete head;
					head = curr = temp;
					if (!head) tail = NULL;
					size--;
					return true;
				}
				curr = head;
				for (uint j = 0; j<i - 1; j++){ curr = curr->next; }
				temp = curr->next->next;
				delete curr->next;
				curr->next = temp;
				size--;
				if (!temp) tail = curr;
				return true;
			}
			bool SetCur(uint i = 0)
			{
				if (!head || i >= this->size) return false;
				curr = head;
				for (uint j = 0; j<i; j++) { if (curr) curr = curr->next; else return false; }
				return true;
			}
			bool Set(uint i, T key)
			{
				if (!SetCur(i)) return false;
				curr->key = key;
				return true;
			}
			void Swap(uint i, uint j)
			{
				T temp;
				temp = (*this)[i];
				Set(i, (*this)[j]);
				Set(j, temp);
			}
			//При заполнении списка числами функция Next может вернуть ложное значение ключа, т.к. возвращает NULL в случае, если указатель на текущий элемент указывает на 0.
			T Next()
			{
				if (!curr) return (T)NULL;
				T temp;
				temp = curr->key;
				curr = curr->next;
				return temp;
			}
			void Clear()
			{
				uint n = size;
				for (uint i = 0; i<n; i++) Pop();
			}
			T operator [](uint i)
			{
				if (!SetCur(i)) return NULL;
				else return curr->key;
			}
			int GetPos(T key)
			{
				if (!SetCur()) return -1;
				for (uint i = 0; i<size; i++)
				{
					if (curr->key != key) Next();
					else return i;
				}
				return -1;
			}
			void operator +=(T key){ Push(key); }
			void operator -=(T key){ Remove(key); }
			void operator = (List<T> &list)
			{
				this->Clear();
				for (uint i = 0; i < list.Size(); i++){ this->Push(list[i]); }
			}
		private:
			//нельзя вызывать без определения функции сравнения
			void QSort(uint left, uint right)
			{
				uint temp;
				if (left<right)
				{
					temp = QSortPartition(left, right);
					if(temp != left /*&& temp!=right*/) QSort(left, temp);
					if (temp + 1 < right) QSort(temp + 1, right);
				}
			}
			//функция возвращающая границу разбиения для функции quickSort
			uint QSortPartition(uint left, uint right)
			{
				//принцип разбиения: a[i]<x | a[i]>=x , где x - произвольное число из массива
				T x;
				uint i = left, j = right, xIndex = left;
				x = (*this)[xIndex];//опорный элемент
				for (;;)
				{
					//находим элемент меньше опорного, идя от правого конца
					while (j != left && !((*LessRelation)((*this)[j], x)))
					{
						j--;//если a[j]<x, то оставляем a[j] на месте и сдивгаем указатель на элемент a[j-1]
					}
					//находим элемент >= опорного, идя от левого конца
					while (i<j && (*LessRelation)((*this)[i], x))
					{
						i++;//если a[i]>=x, то оставляем a[i] на месте и сдивгаем указатель на элемент a[i+1]
					}
					if (i<j) Swap(i, j);//меняем местами меньший элемент a[j] с большим a[i], чтобы справа оказались элементы >x, а слева <=x
					else return j;
				}
			}
		public:
			void Sort(bool(*lessRelation)(T a, T b), bool reverse = false)
			{
				if (!size) return;
				if (lessRelation) LessRelation = lessRelation;
				QSort(0, size-1);
				if (reverse) Reverse();
			}
			void Reverse()
			{
				if (!size) return;
				for (uint i = 0, j = size - 1; i < j; i++, j--)
				{
					Swap(i, j);
				}
			}
		};

	class String
	{
	public:
		wchar_t *str;
		uint reserved, size;
	public:
		String();
		String(const String &srcString);
		String(int reservedSize);
		String(const wchar_t *s);
		String(SYSTEMTIME &time);
		~String();
		void Pop();
		void Pop(uint start, uint length);
		bool Push(const wchar_t *s, uint caret, uint line = 0);
		uint GetIterator(uint caret, uint line);
		wchar_t operator[](uint i);

		String& operator=(const wchar_t *s);
		String& operator=(const char *s);
		String& operator=(String &s);
		String& operator+=(const wchar_t *s);
		String& operator+=(const String &s);
		String& operator+=(int n);
		String& operator+=(const char *s);
		bool operator==(SAL::String &s);
		bool operator!=(SAL::String &s);

		template <class T> static uint StrLength(const T *Str);
		static wchar_t* IntToStr(int n);
		static wchar_t* CharToWchar(const char* cstr);
	};
	SAL::String& operator+(SAL::String &Str, const wchar_t *s);
	SAL::String& operator+(SAL::String &Str, const char *s);
	SAL::String& operator+(const wchar_t *s, SAL::String &Str);
	bool operator==(const wchar_t *s, SAL::String &Str);
	bool operator>=(const wchar_t *s, SAL::String &Str);
	bool operator<=(const wchar_t *s, SAL::String &Str);
}