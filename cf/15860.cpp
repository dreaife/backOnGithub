#include<iostream>
#include<list>
#include<cstring>
using namespace std;
const int MAXLEN = 1e5+10;



class Num{
    class Node{
	public:
		int val;
		Node*next;
		Node(int v, Node*n)
		{
			val = v;
			next = n;
		}
	};
	Node*head;
	int size;
    bool D;
    public:
    Num(){
		head = NULL;
		size = 0;
		D = false;
	}
    Num(string&s){
		D = false;
		head = NULL;
		size = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == ','||s[i]=='-')
				continue;
			size++;
			if (s[i] == '.')
				head = new Node(-100, head);
			else
				head = new Node(s[i] - '0', head);
		}
	}
    Num(const Num& num)
	{
		D = num.D;
		size = num.size;
		head = NULL;
		Node*cur = num.head, *temp=head;
		while (cur)
		{
			if (!head)
			{
				head = new Node(cur->val, NULL);
				temp = head;
			}
			else
			{
				temp->next = new Node(cur->val, NULL);
				temp = temp->next;
			}
			cur = cur->next;
		}
	}
	Num& operator=(const Num&num){
		if (this == &num)
			return *this;
		free();
		size = num.size;
		head = NULL;
		D = num.D;
		Node*cur = num.head, *temp=head;
		while (cur)
		{
			if (!head)
			{
				head = new Node(cur->val, NULL);
				temp = head;
			}
			else
			{
				temp->next = new Node(cur->val, NULL);
				temp = temp->next;
			}
			cur = cur->next;
		}
		return *this;
	}
    ~Num(){
		free();
	}
	void free(){
		size = 0;
		while (head)
		{
			Node*temp = head->next;
			delete head;
			head = temp;
		}
		head = NULL;
	}
    Num& operator+=(const Num&num){
		Node*pa = head, *pb = num.head;
		while (pa||pb)
		{
			int b = 0;
			if (pb)
			{
				b = pb->val;
				pb = pb->next;
			}
			if (pa->val != -100)
			{
				pa->val += b;
				if (pa->val > 9)
				{
					if (pa->next)
					{
						if (pa->next->val == -100)
							pa->next->next->val++;
						else
							pa->next->val++;
					}
					else
					{
						pa->next = new Node(1, NULL);
						size++;
					}
					pa->val -= 10;
				}
			}
			pa = pa->next;
		}
		return *this;
	}
	Num& operator-=(const Num&num){
		Node*pa = head, *pb = num.head;
		while (pa || pb)
		{
			int b = 0;
			if (pb)
			{
				b = pb->val;
				pb = pb->next;
			}
			if (pa->val != -100)
			{
				pa->val -= b;
				if (pa->val < 0)
				{
					if (pa->next->val == -100)
						pa->next->next->val--;
					else
						pa->next->val--;
					pa->val += 10;
				}
			}
			pa = pa->next;
		}
		return *this;
	}
    friend ostream& operator<<(ostream&os, const Num&num){
		bool z = false;
		Num::Node* temp = num.head;
		string s(num.size, '0');
		for (int i = num.size - 1; i >= 0; --i)
		{
			if (temp->val == -100)
			{
				s[i] = '.';
				z = true;
			}
			else
				s[i] = temp->val + '0';
			temp = temp->next;
		}
		if (num.D)
		{
			if (s.size() <= 11)
				s = "0" + string(11 - s.size(), '0') + s;
			if (s[s.size() - 1] > '4')
				s[s.size() - 2]++;
			s.erase(s.end() - 1);
			for (int j = s.size() - 1; j > 0; --j)
			{
				if (s[j] > '9')
				{
					s[j - 1]++;
					s[j] -= 10;
				}
				else
					break;
			}
			if (s[0] > '9')
			{
				s[0] -= 10;
				s = "1" + s;
			}
			s.insert(s.size() - 10, ".");
			z = true;
		}
		int n = 0;
		while (s[n] == '0')
			n++;
		if (n == s.size())
			s = "0";
		else
			s = s.substr(n);
		if (s[0] == '.')
			s = '0' + s;
		bool t = true;
		int q;
		for (q = 0; q < s.size(); ++q)
			if (s[q] == '.')
				break;
		int j = s.size() - 1;
		if (z)
		{
			while (j > q&&s[j] == '0')
				j--;
			if (j == q)
				j--;
		}
		for (int i = 0; i <= j; ++i)
		{
			if (s[i] == '.')
				t = false;
			os << s[i];
		}
		os << endl;
		return os;
	}
};

int main(){
    string t1,t2;
    cin>>t1>>t2;
    Num a(t1),b(t2);
    Num resAdd(a),resDiv(a);
    resAdd+=b;resDiv-=b;
    cout<<resAdd<<endl<<resDiv<<endl;
    return 0;
}