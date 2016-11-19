#include "math.h"
#include "stdio.h"
struct node{
	double x;
	double f;
	double R;
	node* next;
	node* prev;
};

class list {
public:
	node *head=new node;
	node *tail=new node;
	~list(){ while (head) { tail = head->next; delete head; head = tail; } }

	list(double _a) {
		head->x = _a;
		head->f = f(_a);
		head->R = 0;
		head->prev = 0;
		head->next = tail;
	}

	list(double _b, double _r) {
		tail->x = _b;
		tail->f = f(_b);
		//double m = mm(_r);
		//tail->R = tail->R = m*(tail->x - tail->prev->x - 1) + (((tail->f - tail->prev->f - 1)*(tail->f - tail->prev->f - 1)) / (m*(tail->x - tail->prev->x))) - 2 * (tail->f + tail->prev->f);
		tail->prev = head;
		tail->next = 0;
	}
	void add(double _val, double val){
		node* tmp = new node;
		tmp->x = val;
		tmp->f = f(val);
		node* srch = search(_val);
		node* tmp1 = srch->next;
		srch->next = tmp;
		tmp->prev = srch;
		tmp->next = tmp1;	
	}
	node* search(double _val){
		node *tmp1 = head;
		while (tmp1->x != _val&&tmp1->next != 0)
			tmp1 = tmp1->next;
		return tmp1; 
	}
	void print() {
		node*tmp = head;
		while (tmp != 0) {
			printf("x = %lf y = %lf \n", tmp->x, tmp->f);
			tmp = tmp->next;	
		}
	
	}
	void printcurr(double _x) {
		node* tmp = search(_x);
		printf("x = %lf y = %lf \n", tmp->x, tmp->f);	
	}
	double f(double _val) { return (_val)*(_val); }
	double mm(double r){
		double M = 0;
		double M1 = 0;
		double m = -1000;
		node*t1 = head;
		node*t2 = head->next;
		M = abs((t1->f - t2->f - 1) / (t1->x - t2->x - 1));
		t1 = t1->next;
		t2 = t2->next; 
		double tmp = 0;
		while (t2!=0) {
			M1 = abs((t1->f - t2->f - 1) / (t1->x - t2->x - 1));
			tmp = fmax(M, M1);
			if (tmp > m)
				m = tmp;
			M = M1;
			t2 = t2->next;
			t1 = t1->next;
		}
		if (m > 0)
			return m*r;
		if (m = 0)
			return 1;
	}
		void Rr(node* tmp, double r) {	
			double m = mm(r);
			tmp->R = m*(tmp->x - tmp->prev->x - 1) + (((tmp->f - tmp->prev->f - 1)*(tmp->f - tmp->prev->f - 1)) / (m*(tmp->x - tmp->prev->x))) - 2 * (tmp->f + tmp->prev->f);
			tmp->next->R = m*(tmp->next->x - tmp->x - 1) + (((tmp->next->f - tmp->f - 1)*(tmp->next->f - tmp->f - 1)) / (m*(tmp->next->x - tmp->x))) - 2 * (tmp->next->f + tmp->f);
	}
		node* searchmaxR(){
			node* tmp = head->next;
			node* maxR = new node;
			while (tmp != 0){
				if (tmp->R > maxR->R)
					maxR = tmp;
				tmp = tmp->next;
			}
			return maxR;
		}
		void insert(double r, double e){
			node *tmp=new node;
			tmp = searchmaxR();
			double m = mm(r);
			double xx = (1 / 2)*(tmp->x + tmp->prev->x) - ((f(tmp->x) - f(tmp->prev->x)) / (2 * m));
			add(tmp->prev->x, xx);
		}
		bool epsilon(node * A, double e) {
			if ((A->x - A->prev->x) < e || (A->next->x - A->x) < e)
				return true;
			else return false;
		}
};