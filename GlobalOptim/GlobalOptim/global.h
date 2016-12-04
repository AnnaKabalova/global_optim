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
	~list(){ while (head) { node* tmp = head->next; delete head; head = tmp; } }

	list(double _a) {
		head->x = _a;
		head->f = f(_a);
		head->R = 0;
		head->prev = 0;
		head->next = 0;
		}
	void addtail(double _val, double val, double _r) {
		node *tmp = new node;
		node *tmp1 = search(_val);
		node *tmp2 = tmp1->next;
		tmp->x = val;
		tmp->f = f(val);
		tmp1->next = tmp;
		tmp->prev = tmp1;
		tmp->next = tmp2;
		double m = mm(_r);
		Rr(tmp, _r);
	}
	void add(node* tmp1, node* curr, double val, double _r){
		node* tmp = new node;
		tmp->x = val;
		tmp->f = f(val);
		tmp1->next = tmp;
		tmp->prev = tmp1;
		tmp->next = curr;
		curr->prev = tmp;
		double m = mm(_r);
		Rr(tmp, _r);
	}
	node* search(double _val){
		node *tmp1 = head;
		while (tmp1->x != _val&&tmp1->next != 0)
			tmp1 = tmp1->next;
		return tmp1; 
	}
	void searchmin() {
		node *tmp1 = head->next;
		node *min = head;
		while (tmp1 != 0) {
			if (tmp1->f < min->f)
				min = tmp1;
			tmp1 = tmp1->next;
		}
		printcurr(min);
	}

	void print() {
		node*tmp = head;
		while ( tmp!=0 ){
			printf("x = %lf y = %lf R = %lf \n", tmp->x, tmp->f, tmp->R);
			tmp = tmp->next;	
		 }	
	}
	void printcurr(node *A) {
		printf("min x = %lf min y = %lf \n", A->x, A->f);	
	}
	double f(double _val) { return (_val)*(_val); }
	double mm(double r){
		double M = 0;
		double M1 = 0;
		double m = -1000;
		node*t1 = head;
		node*t2 = head->next;
		M = fabs((t1->f - t2->f - 1) / (t1->x - t2->x - 1));
		t1 = t1->next;
		t2 = t2->next; 
		if (t2 == 0) {
			if (M > 0)
				return m = M*r;
			if (M == 0)
				return m = 1;
		
		}
		double tmp = 0;
		while (t2!=0) {
			M1 = fabs((t1->f - t2->f - 1) / (t1->x - t2->x - 1));
			tmp = fmax(M, M1);
			if (tmp > m)
				m = tmp;
			M = M1;
			t2 = t2->next;
			t1 = t1->next;
		}
		if (m > 0)
			return m*r;
		if (m == 0)
			return 1;
	}
		void Rr(node* tmp, double r) {	
			double m = mm(r);
			tmp->R = m*(tmp->x - tmp->prev->x - 1) + (((tmp->f - tmp->prev->f - 1)*(tmp->f - tmp->prev->f - 1)) / (m*(tmp->x - tmp->prev->x))) - 2 * (tmp->f + tmp->prev->f);
			if (tmp->next!=0)
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
		bool insert(double _r, double e){
			node *tmp=new node;
			node *tmp1 = new node;
			tmp = searchmaxR();
			tmp1 = tmp->prev;
			double m = mm(_r);
			double xx = 0.5*(tmp->x + tmp->prev->x) - ((tmp->f - tmp->prev->f) / (2 * m));
			add(tmp1,tmp, xx, _r);
			//Rr(tmp, _r);
			bool flag = epsilon(tmp1->next, e);
			return flag;
		}
		bool epsilon(node * A, double e) {
			if (((A->x - A->prev->x) > e) || ((A->next->x - A->x) > e))
				return true;
			else return false;
		}
};