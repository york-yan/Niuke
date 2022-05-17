

/*
 * 面试题38
 * 字符串的排列
 */

////////////////////////////////////////////////////
/*
 * 面试题37
 * 序列化和反序列化
 */
/*#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;
struct TreeNode {
	int val;
	TreeNode*left;
	TreeNode*right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};
TreeNode* GetTree(vector<char>vec) {
	vector<TreeNode*> vecTree = { vec.size(),nullptr };
	TreeNode* root = nullptr;
	for(int i=0;i<vec.size();i++) {
		TreeNode* node = nullptr;
		if (vec[i] != '#')
			node = new TreeNode((int)vec[i]-48);
		vecTree[i] = node;
		if (i == 0)
			root = node;
	}
	for(int i=0;2*i+2<vecTree.size();i++) {
		if(vecTree[i]!=nullptr) {
			vecTree[i]->left = vecTree[2 * i + 1];
			vecTree[i]->right = vecTree[2 * i + 2];
		}
	}
	return root;
}
void GetChar(TreeNode* root,string &s) {
	
	if (root == nullptr)
		s += '#';
	else {
		s += to_string(root->val);
		s += ',';
		GetChar(root->left, s);
		GetChar(root->right, s);
	}
	
	
}
int main() {
	char n;
	vector<char> vec;
	while(cin>>n) {
		vec.push_back(n);
		if (cin.get() == '\n')
			break;
	}
	TreeNode*root = GetTree(vec);
	string s = {};
	GetChar(root,s);
	return 0;
}*/

////////////////////////////////////////////////////////////
/*
 * 面试题36
 * 二叉树与双向链表的的转换
 */
/*
#include<iostream>
#include<vector>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};
TreeNode *GetTree( vector<int>vec) {
	vector<TreeNode*> vecTree = { vec.size(),nullptr };
	TreeNode* root = nullptr;
	for(int i=0;i<vec.size();i++) {
		TreeNode* node = nullptr;
		if (vec[i] != -1)
			node = new TreeNode(vec[i]);
		vecTree[i] = node;
		if (i == 0)
			root = node;
	}
	for(int i=0;i*2+2<=vecTree.size();i++) {
		if(vecTree[i]!=nullptr) {
			vecTree[i]->left = vecTree[i * 2 + 1];
			vecTree[i]->right = vecTree[i * 2 + 2];
		}
	}
	return root;
}

class Slu {
	
public:
	TreeNode *pre=nullptr;
	
	TreeNode *Convert(TreeNode *root) {
		if (!root) return nullptr;
		TreeNode *head = Convert(root->left);
		
		if (!head) 
			head = root;//此时head指向左下角的节点
		root->left = pre;
		if (pre) {
			pre->right = root;  //建立连接
		}
		pre = root;
		
		Convert(root->right);
		return head;
	}
	
};
int main() {
	int n;
	vector<int> vec;
	while(cin>>n) {
		vec.push_back(n);
		if (cin.get() == '\n')
			break;
	}
	TreeNode*root = GetTree(vec);
	Slu slu;
	TreeNode* dTree = slu.Convert(root);
	return 0;
}
*/


///////////////////////////////////////////////////////////
/*
 * 面试题35
 * 复杂链表的复制
 * 有点难，没看得很懂
 * 但是主要的思想是先用一个哈希表映射过去，然后看有没有random指针
 */


////////////////////////////////////////////////////////////
/*
 * 面试题34
 * 二叉树中和位某一值的路径
 */
/*#include<iostream>
#include<vector>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};
TreeNode *GetTree(vector<int> vec) {
	vector<TreeNode*> vecTree = { vec.size(),nullptr };
	TreeNode *root = nullptr;
	for(int i=0;i<vec.size();i++) {
		TreeNode *node = nullptr;
		if (vec[i] != -1)
			node=new TreeNode(vec[i]);
		vecTree[i] = node;
		if (i == 0)
			root = node;
	}
	for(int i=0;i*2+2<=vecTree.size();i++) {
		if (vecTree[i] != nullptr) {
			vecTree[i]->left = vecTree[i * 2 + 1];
			vecTree[i]->right = vecTree[i * 2 + 2];
		}
	}
	return root;
}

class Slu {
public:
	vector<vector<int>> FindPath(TreeNode* root, int target) {
		if (root)
			dfsFind(root, target);
		return res;
	}
	void dfsFind(TreeNode* root, int target) {
		temp.push_back(root->val);
		if (root->val == target)
			res.push_back(temp);
		if(root->val<target) {
			if (root->left)		dfsFind(root->left, target - root->val);
			if (root->right)	dfsFind(root->right, target - root->val);
		}
		temp.pop_back();
	}
private:
	vector<int> temp;
	vector<vector<int>> res;
};


int main() {
	int n;
	vector<int> vec;
	while (cin >> n) {
		vec.push_back(n);
		if (cin.get() == '\n')
			break;
	}
	TreeNode* root = GetTree(vec);
	
	Slu slu;
	vector<vector<int>> res=slu.FindPath(root, 22);
	
	return 0;
}*/


////////////////////////////////////////////////////////////////////
/*
 * 面试题33
 * 二叉搜索树的后续遍历序列
 * 分而治之，二叉搜索树具有平衡性，根节点前面的一定比根节点小，
 */
/*
#include<iostream>
#include <vector>
using namespace std;
struct TreeNode {
	int val;
	TreeNode*left;
	TreeNode*right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};
TreeNode *GetTree(vector<int> vec) {
	vector<TreeNode*> vecTree = { vec.size(),nullptr };
	TreeNode *root = nullptr;
	TreeNode *node = nullptr;
	for(int i=0;i<vec.size();i++) {
		if (vec[i]!='-1') 
			node->val = vec[i];
		vecTree[i] = node;
		if (i==0) 
			root = node;
	}
	for(int i=0;i*2+2<=vecTree.size();i++) {
		if(vecTree[i]!=nullptr) {
			vecTree[i]->left = vecTree[i * 2 + 1];
			vecTree[i]->right = vecTree[i * 2 + 2];
		}
	}
	return root;
}
bool isBST(vector<int> squence, int start, int end) {
	if (start >= end)	return true;
	int low = start;
	while (low < end && squence[low] < squence[end])
		++low;
	for(int i=low;i<end;i++) {
		if (squence[i] < squence[end])
			return false;
	}
	return isBST(squence, start, low - 1) &&
		isBST(squence, low , end - 1);
}
bool SquenceIsBST(vector<int> squence) {
	if (squence.empty())	return false;
	if (squence.size() == 1)	return true;
	return isBST(squence, 0, squence.size() - 1);
}


int main() {
	vector<int> vec = { 3,1,2 };
	bool flag = SquenceIsBST(vec);
	return 0;
}
*/



//////////////////////////////////////////////////////////////////////////////
/*
 * 面试题32
 * 从上往下打印二叉树
 */
/*#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};
TreeNode *GetTree(vector<char> vec) {
	vector<TreeNode*> vecTree(vec.size(), nullptr);
	TreeNode *root=nullptr;
	for(int i=0;i<vec.size();i++) {
		TreeNode* node = nullptr;
		if (vec[i] != '#')
			node = new TreeNode((int)vec[i]);
		vecTree[i] = node;
		if (i == 0)
			root = node;
	}
	for(int i=0;i*2+2<=vecTree.size();i++) {
		if(vecTree[i]!=nullptr) {
			vecTree[i]->left = vecTree[2 * i + 1];
			vecTree[i]->right = vecTree[2 * i + 2];
		}
	}
	return root;
}

vector<int> PrintTree(TreeNode *root) {
	queue<TreeNode*>m_queue_;
	vector<int> rlt={};
	if (!root) {
		return rlt;
	}
	m_queue_.push(root);
	while(!m_queue_.empty()) {
		rlt.push_back(m_queue_.front()->val);
		if (m_queue_.front()->left) {
			m_queue_.push(m_queue_.front()->left);
		}
		if (m_queue_.front()->right) {
			m_queue_.push(m_queue_.front()->right);
		}
		m_queue_.pop();
	}
	return rlt;
	
}


int main() {
	int n;
	vector<char>vec;
	while(cin>>n) {
		vec.push_back(n);
		if (cin.get() == '\n')
			break;
	}
	TreeNode *root = GetTree(vec);
	vector<int> res = PrintTree(root);
	return 0;
}*/


//////////////////////////////////////////////
/*
 * 面试题31
 * 栈的压入弹出序列，辅助栈，遇王则停
 */
/*#include<iostream>
#include<stack>
#include<vector>
using namespace std;
bool IsRight(vector<int> input,vector<int> target) {
	if (input.size() != target.size())
		return false;
	stack<int> stk;
	int i = 0;
	int j = 0;
	while(i<input.size()) {
		stk.push(input[i]);
		while(j<target.size() && !stk.empty() && stk.top() == target[j]) {
		
				stk.pop();
				j++;
			
		
		}
		i++;
	}
	return stk.empty();
}

int main() {
	vector<int> input = { 2,1,0 };
	vector<int> target = { 1,2,0};
	bool flag=IsRight(input, target);
	return 0;
}*/

//////////////////////////////////////////////////////////////
/*
 * 面试题30
 * 包含MIN函数的栈
 */
/*
#include<iostream>
#include<vector>
#include<stack>

using namespace std;
class mystk {
private:
	stack<int> stk1;
	stack<int> stk2;
public:
	void push(int value) {
		stk1.push(value);
		if (stk2.empty() || value < stk2.top())
			stk2.push(value);
		else
			stk2.push(stk2.top());
	}
	void pop() {
		stk1.pop();
		stk2.pop();
	}
	int top() {
		if (stk1.empty())
			return NULL;
		return stk1.top();
	}
	int min() {
		if (stk2.empty())
			return NULL;
		return stk2.top();
	}
};
int main() {
	mystk stk;
	stk.push(1);
	stk.push(0);
	stk.push(3);
	int minx=stk.min();
	return 0;
}
*/

////////////////////////////////////////////////////////////////
/*
 * 面试题29
 * 顺时针打印矩阵
 * 找到四个顶点然后依次遍历
 */
/*#include<iostream>
#include<vector>
using namespace std;
vector<int> PrintMatrix(vector<vector<int>> vecs) {
	vector<int> rlt;
	int m = vecs.size();
	int n = vecs[0].size();
	if (m == 0)	return rlt;
	int up = 0;
	int down = m - 1;
	int left = 0;
	int right = n - 1;
	while (up <= down && left <= right) {
		for (int i = left; i <= right; i++) {
			rlt.push_back(vecs[up][i]);
		}
		up++;
		if (up > down)
			break;
		for (int j = up; j <= down; j++) {
			rlt.push_back(vecs[j][right]);
		}
		right--;
		if (left > right)
			break;
		for (int i = right; i >= left; i--) {
			rlt.push_back(vecs[down][i]);
		}
		down--;
		if (up > down)
			break;
		for(int j=down;j>=up;j--) {
			rlt.push_back(vecs[j][left]);
		}
		left++;
		if (left > right)
			break;
	}
	return rlt;
}
int main() {
	int row, col;
	cin >> row >> col;
	vector<vector<int>> vecs(row, vector<int>(col));
	for(int i=0;i<row;i++) {
		for (int j = 0; j < col; j++)
			cin >> vecs[i][j];
	}
	vector<int>res = PrintMatrix(vecs);
	return 0;
}*/
///////////////////////////////////////////////////////
/*
 * 面试题28
 * 对称二叉树
 */
/*
#include<iostream>
#include<vector>
using namespace  std;
struct ListNode {
	int val;
	ListNode *left;
	ListNode *right;
	ListNode(int x):val(x),left(nullptr),right(nullptr){}
};
ListNode *GetList(vector<int>vec) {
	vector<ListNode*> vecTree(vec.size(), nullptr);
	ListNode *root = nullptr;
	for(int i=0;i<vec.size();i++) {
		ListNode *node = nullptr;
		if (vec[i] != -1)
			node = new ListNode(vec[i]);
		vecTree[i] = node;
		if (i == 0)
			root = node;
	}
	for(int i=0;i*2+2<=vecTree.size();i++) {
		if(vecTree[i]!=nullptr) {
			vecTree[i]->left = vecTree[2 * i + 1];
			vecTree[i]->right = vecTree[2 * i + 2];
		}
	}
	return root;
}
bool issame(ListNode *root1, ListNode *root2) {
	if (!root1 && !root2)	return true;
	if (!root1 || !root2)	return false;
	return root1->val == root2->val &&
		issame(root1->left, root2->right) &&
		issame(root1->right, root2->left);
}
bool IsSymmetrical(ListNode *proot) {
	return issame(proot,proot);
}


int main() {
	vector<int> vec;
	int n;
	while(cin>>n) {
		vec.push_back(n);
		if (cin.get() == '\n')
			break;
	}
	ListNode* root = GetList(vec);
	bool rlt=IsSymmetrical(root);
	return 0;
}
*/

////////////////////////////////////////////////////////////
/*
 * 面试题27
 * 二叉树的镜像
 */
/*
#include<iostream>
#include<sstream>
#include<vector>

using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};
//构造数组
/*输入负数有问题#1#
/*vector<int> GetVector(string input) {
	vector<int> ans;
	stringstream ss;
	ss.str(input);
	string item;
	char delim = ',';
	while(getline(ss,item,delim)) {
		ans.push_back(stoi(item));
	}
	return ans;
}#1#
//由数组构造树
TreeNode *GetTree(vector<int> vec) {
	vector<TreeNode*> vecTree(vec.size(), nullptr);
	TreeNode *root = nullptr;
	for(int i=0;i<vec.size();i++) {
		TreeNode *node = nullptr;
		if (vec[i] != -1)
			node = new TreeNode(vec[i]);
		vecTree[i] = node;
		if (i == 0)
			root = node;
	}
	for(int i=0;i*2+2<=vecTree.size();i++) {
		if(vecTree[i]!=nullptr) {
			vecTree[i]->left = vecTree[i * 2 + 1];
			if (vecTree.size() > i * 2 + 2)
				vecTree[i]->right = vecTree[i * 2 + 2];
			else
				vecTree[i]->right = nullptr;
		}
	}
	return root;
}

TreeNode *Mirror(TreeNode *proot) {
	if (proot == nullptr)	return nullptr;
	if(proot->left || proot->right) {
		TreeNode *temp = proot->left;
		proot->left = proot->right;
		proot->right = temp;
	}
	Mirror(proot->left);
	Mirror(proot->right);
	return proot;
	
}

int main() {
	//string input;
	//cin >> input;
	//vector<int> ans = GetVector(input);
	vector<int>ans;
	int n;
	while(cin>>n) {
		ans.push_back(n);
		if (cin.get() == '\n')
			break;
	}
	
	TreeNode*root = GetTree(ans);
	TreeNode*Rroot = Mirror(root);
	return 0;
}
*/

//////////////////////////////////////////////////////////
/*
 * 面试题26
 * 树的子结构
 */
/*#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};
TreeNode *GetTree(vector<int> vec) {
	vector<TreeNode*> vecTree(vec.size(), nullptr);
	TreeNode* root = nullptr;
	for(int i=0;i<vec.size();i++) {
		TreeNode *node = nullptr;
		if (vec[i] != -1)
			node = new TreeNode(vec[i]);
		vecTree[i] = node;
		if (i == 0)
			root = node;
	}
	for(int i=0;i*2+2<=vec.size();i++) {
		if(vecTree[i]!=nullptr) {
			vecTree[i]->left = vecTree[i * 2 + 1];
			if (vecTree.size() > i * 2 + 2)
				vecTree[i]->right = vecTree[i * 2 + 2];
			else
				vecTree[i]->right = nullptr;
		}
	}
	return root;
}
bool Tree1HasTree2(TreeNode *p1,TreeNode *p2) {
	if (p2 == nullptr)
		return true;
	if (p1 == nullptr && p2 == nullptr)
		return true;
	if (p1->val != p2->val)
		return false;
	return Tree1HasTree2(p1->left, p2->left) && Tree1HasTree2(p1->right, p2->right);
}
bool HasSubTree(TreeNode *p1, TreeNode *p2) {
	//bool res = false;
	if (p1 == nullptr || p2 == nullptr)   //空节点不是子树
		return false;
	return Tree1HasTree2(p1, p2) ||    //不需要遍历找到p1与p2的头，直接对比
		HasSubTree(p1->left, p2) ||
		HasSubTree(p1->right, p2);
}

vector<int> getVector(string input) {
	vector<int> ans;
	stringstream ss;
	ss.str(input);
	string item;
	char delim = ',';
	while (getline(ss, item, delim)) {
		ans.push_back(stoi(item));
	}
	cout << "节点输入完成" << endl;
	return ans;
}

int main() {
	/*int n;
	vector<int> vec;
	while(cin>>n) {
		vec.push_back(n);
		if (cin.get()=='\n') 
			break;
	}#1#

	string input;
	cin >> input;
	
	vector<int> vec = getVector(input);
	
	
	TreeNode *root = GetTree(vec);
	int m;
	vector<int> res;
	while(cin>>m) {
		res.push_back(m);
		if (cin.get() == '\n')
			break;
	}
	TreeNode* p2 = GetTree(res);
	bool rlt=HasSubTree(root, p2);

	
	return 0;
}*/

/////////////////////////////////////////////////////////
/*
 * 面试题25
 * 合并两个有序链表（递归）
 */
/*
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(nullptr){}
};
ListNode *GetList(vector<int> vec) {
	ListNode *dummyhead = new ListNode(-1);
	ListNode *p = dummyhead;
	for(int i=0;i<vec.size();i++) {
		p->next = new ListNode(vec[i]);
		p = p->next;
	}
	return dummyhead->next;
}
ListNode *MergeList(ListNode *p1,ListNode *p2) {
	ListNode *pnew = nullptr;
	if (p1 == nullptr)	return p2;
	if (p2 == nullptr)	return p1;
	if(p1->val<p2->val) {
		pnew = p1;
		pnew->next= MergeList(p1->next, p2);
	}else {
		pnew = p2;
		pnew->next = MergeList(p1, p2->next);
	}
	return pnew;
}
vector<int> getVector(string input) {
	vector<int> ans;
	stringstream ss;
	ss.str(input);
	string item;
	char delim = ',';
	while (getline(ss, item, delim)) {
		ans.push_back(stoi(item));
	}
	cout << "节点输入完成" << endl;
	return ans;
}
int main() {
	int n1;
	vector<int> vec1;
	string imput;
	cin >> imput;
	vec1 = getVector(imput);
	/*while (cin>>n1) {
		if (getchar()== '\n')
			break;
		vec1.push_back(n1);
		
	}#1#
	/*int n2;
	vector<int> vec2;
	while (cin >> n2) {
		vec2.push_back(n2);
		if (cin.get() == '\n')
			break;
	}#1#
	ListNode *p1 = GetList(vec1);
	//ListNode *p2 = GetList(vec2);
//	ListNode *pnew = MergeList(p1, p2);
	return 0;
}
*/


/////////////////////////////////////////////////////
/*
 * 面试题24
 * 反转链表
 */
/*#include<iostream>
#include<vector>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(nullptr){}
};
ListNode *GetList(vector<int> vec) {
	ListNode *dummyhead = new ListNode(-1);
	ListNode *p = dummyhead;
	for(int i=0;i<vec.size();i++) {
		p->next = new ListNode(vec[i]);
		p = p->next;
	}
	return dummyhead->next;
}
/*
 *辅助空间
 *ListNode *ReverseList(ListNode *proot) {
	vector<int> vec;
	while(proot) {
		vec.push_back(proot->val);
		proot = proot->next;
	}
	ListNode *dummyhead = new ListNode(-1);
	ListNode *p = dummyhead;
	for(int i=vec.size()-1;i>=0;i--) {
		p->next = new ListNode(vec[i]);
		p = p->next;
	}
	return dummyhead->next;
}#1#

//原地反转
ListNode *ReverseList(ListNode *pHead) {
	ListNode *pReversed = nullptr;
	ListNode *pNode = pHead;
	ListNode *pre = nullptr;
	while(pNode!=nullptr) {
		ListNode *pNext = pNode->next;
		if(pNext==nullptr) {
			pReversed = pNode;
		}
		pNode->next = pre;
		pre = pNode;
		pNode = pNext;
	}
	return pReversed;
}


int main() {
	int n;
	vector<int> vec;
	while(cin>>n) {
		vec.push_back(n);
		if (cin.get() == '\n')
			break;
	}
	ListNode *proot= GetList(vec);
	ListNode *rp = ReverseList(proot);
	return 0;
}*/

/////////////////////////////////////////////////////////////////////
/*
 * 面试题23
 * 链表中环的入口节点
 */
/*#include<iostream>
#include<vector>

using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(nullptr){}
};

ListNode* HaveRing(ListNode* proot) {
	if (!proot->next) return nullptr;
	ListNode *plow = proot->next;
	if (!plow->next)	return nullptr;
	ListNode *pfast = plow->next;
	while(pfast) {
		if(pfast==plow) {
			return pfast;
		}
		plow = plow->next;
		pfast = pfast->next;
		if(pfast->next) {
			pfast = pfast->next;
		}
	}
	return nullptr;
}

int MeetingNode(ListNode *proot,ListNode *pring) {
	int count = 0;
	ListNode *p = pring;
	while(p->next!=pring) {
		++count;
		p = p->next;
	}
	ListNode *pnew = proot;
	for(int i=0;i<count;i++) {
		pnew = pnew->next;
	}
	while(pnew!=proot) {
		pnew = pnew->next;
		proot = proot->next;
	}
	return pnew->val;
}

int main() {
	ListNode *p = new ListNode(1);
	p->next = new ListNode(2);
	p->next->next = new ListNode(3);
	p->next->next->next = p;
	ListNode* ring = HaveRing(p);
	int value = MeetingNode(p, ring);
	system("pause");
	return 0;
}*/


////////////////////////////////////////////////////////////
/*
 * 面试题22
 * 链表倒数k个节点
 */
/*#include<iostream>
#include<vector>
using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(nullptr) {}
};
ListNode* GetList(vector<int> vec) {
	ListNode *dummyhead = new ListNode(-1);
	if (vec.empty()) {
		return nullptr;
	}
	ListNode *p = dummyhead;
	for(vector<int>::iterator it=vec.begin();it!=vec.end();it++) {
		dummyhead->next=new ListNode (*it);
		dummyhead = dummyhead->next;
	}
	return p->next;
}

ListNode* Findkth(ListNode* proot,int k) {
	int length = 0;
	ListNode* p = proot;
	while(proot) {
		length++;
		proot = proot->next;
	}
	if (length < k) return nullptr;
	for(int i=0;i<length-k;i++) {
		p = p->next;
	}
	return p;
}

int main() {
	int n;
	vector<int> vec;
	while(cin>>n) {
		vec.push_back(n);
		if (cin.get() == '\n')
			break;
	}
	int k;
	cin >> k;
	auto list = GetList(vec);
	auto klist = Findkth(list, k);

	return 0;
	
}*/



/////////////////////////////////////////////////////////////
/*
 * 面试题21
 * 数组中计数位于偶数的前面
 */
/*
#include<iostream>
#include<vector>

using namespace std;
vector<int> Reorder(vector<int> vec) {
	vector<int> res;
	vector<int>::iterator it;
	for(it=vec.begin();it!=vec.end();it++) {
		if (*it%2==1) {
			res.push_back(*it);
		}
	}
	for (it = vec.begin(); it != vec.end(); it++) {
		if (*it % 2 == 0) {
			res.push_back(*it);
		}
	}
	return res;
}
int main() {
	int n;
	vector<int> vec;
	while (cin>>n) {
		vec.push_back(n);
		if (cin.get() == '\n')
			break;
	}
	auto a=Reorder(vec);
	return 0;
}
*/

/*
 * 面试题20
 * 表示数值的字符串
 * 暂时空
 */




/*
 * 面试题19
 * 正则表达式
 * !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!----------------没懂
 */
/*
#include<iostream>
#include<string>
using namespace std;

bool Match(string str,string pattern) {
	return to_Match(str, pattern);
}
bool to_Match(string str, string pattern) {
	//设置终止条件
	if (str.size() == 0 && pattern.size() == 0)
		return true;
	if (str.size() && pattern.empty())
		return false;
	if (str.empty() && pattern.size() >= 2 && pattern[1] == '*')
		return to_Match(str, pattern.substr(2));
	if(pattern.size()>=2 && pattern[1]=='*') {
		if ((pattern[0] == str[0] || pattern[0] == '.') && !str.empty()) {
			return to_Match(str, pattern.substr(2))
				|| to_Match(str.substr(1), pattern);
		}
		return to_Match(str, pattern.substr(2));
	}
	if (!str.empty() && (pattern[0] == str[0] || pattern[0] == '.')) {
		return to_Match(str.substr(1), pattern.substr(1));
	}

	return false;
}

int main() {
	
	return 0;
}
*/


//////////////////////////////////////////////////////////////////////////
/*
 * 面试题18
 * 删除链表中的节点
 */
/*#include<iostream>
#include <vector>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(nullptr){}
};
ListNode* GetList(vector<int> vec) {
	ListNode* dummyhead = new ListNode(-1);
	ListNode* proot = dummyhead;
	for(int i=0;i<vec.size();i++) {
		dummyhead->next = new ListNode(vec[i]);
		dummyhead = dummyhead->next;
	}
	return proot->next;
}

ListNode* DeleteNode(ListNode* proot,int val) {
	auto pnew = proot;
	if (proot->val == val)
		return pnew->next;  //判断表头是不是
	while (proot->next->val != val)
		proot = proot->next;   //节点元素不等于目标时，节点往下移动
	
	proot->next = proot->next->next;//该处找到了目标点
	return pnew;
	
	
}

int main() {
	vector<int> vec;
	int number;
	int val;
	while(cin>>number) {
		vec.push_back(number);
		if (cin.get() == '\n')
			break;
	}
	cin >> val;
	auto root = GetList(vec);
	auto p=DeleteNode(root, val);
	system("pause");
	return 0;
}*/

/////////////////////////////////////
/*
 * 面试题17
 * 打印从1到最大的n位数
 */
/*
#include<iostream>
#include<vector>
using namespace std;

vector<int> PrintNumber(int n) {
	vector<int> vec;
	for(int i=1;i<pow(10,n);i++) {
		vec.push_back(i);
	}
	return vec;
}

int main() {
	return 0;
}
*/


///////////////////////////////////////////////////////////////
/*
 * 面试题16
 * 数值的整数次方
 * 不能使用库函数，不需要考虑大数问题
 */
/*
#include<iostream>
using namespace std;
double Power(double base, int exponent) {
	if (exponent<0) {
		exponent = exponent*(-1);  //复数取反，
		base = 1 / base;
	}
	
	if (exponent == 0)
		return 1;
	if (exponent == 1)
		return base;
	double res = Power(base, exponent >> 1);
	res *= res;
	if (exponent & 0x1) {
		res *= base;
	}
	return res;
}

int main() {
	double n;
	 int m;
	cin >> n>>m;
	double res = Power(n, m);
	return 0;
}
*/



/////////////////////////////////////////////////////
/*
 * 面试题15
 * 二进制中1的个数
 */
/*
#include<iostream>
using namespace std;

int NumberOf1(int n) {
	int count = 0;
	unsigned int flag = 1;
	while(flag) {
		if (n&flag)
			count++;
		flag=flag << 1;   //动用flag
	}
	
	/*while(n) {
		if (n&1==1) {
			count++;  //移动n
		}
		n=n >> 1;
	}#1#
	return count;
}

int main() {
	int n;
	cin >> n;
	int m=NumberOf1(n);
	system("pause");
	return 0;
}
*/


//////////////////////////////////////////////////////////////
/*
 * 面试题14
 * 剪绳子
 */
/*#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;*/
/*int CutRope(int number) {
//贪心算法
	//考数学，均值不等式：算术平均>=开方平均
	//故number=mx；x^m=x^(number/x)即
	//{x^(1/x)}^number,所以当x^(1/x)取最大值的时候为最大
	//其驻点为e，取整数要么为3，要么为2，优先取3
	if (number <= 3)
		return number - 1;
	int m = number / 3;
	int l = number % 3;
	if (l == 0) {
		return pow(3, m);
	}
	if(l==1) {
		m = m - 1;
		return pow(3, m ) * 4;
	}
    if (l==2) {
		return pow(3, m) * 2;
	}
}*/

//动态规划
/*
int CutRope(int number) {
	if (number <= 3)
		return number - 1;
	vector<int> sum(number + 1, 0);
	sum[1] = 1;
	sum[2] = 2;
	sum[3] = 3;
	sum[4] = 4;//首先填充前四个
	for (int i = 5; i <=number ; i++) {
		for (int j = 1; j < i; j++) {
			sum[i] = max(sum[i], j*sum[i - j]);
		}
	}
	return sum[number];
	
}

int main() {
	int n;
	cin >> n;
	int sum=CutRope(n);
	system("pause");
	return 0;
}
*/



///////////////////////////////////////////////////////////////
/*
 * 面试题12
 * 矩阵中的路径
 */
/*
#include<iostream>
#include <vector>
#include <string>
using namespace std;

bool dfs(vector<vector<char>> mat,string word,int i, int j,int index) {
	//边缘判断条件，越界和不等于值都判断为失败
	if(i>=mat.size()||i<0||
	   j>=mat[0].size()||j<0||
	   mat[i][j]!=word[index]) {
		return false;
	}
	//终止条件
	if (index == word.length() - 1)
		return true;
	//先保存当前值，防止走回路
	char temp = mat[i][j];
	mat[i][j] = '*';
	//开始遍历
	bool res = dfs(mat, word, i + 1, j, index + 1) ||
		dfs(mat, word, i - 1, j, index + 1) ||
		dfs(mat, word, i, j + 1, index + 1) ||
		dfs(mat, word, i, j - 1, index + 1);
	mat[i][j] = temp;
	return res;
}

bool HasPath(vector<vector<char>> mat, string word) {
	for (int i=0;i<mat.size();i++) {
		for(int j=0;j<mat[0].size();j++) {
			if (dfs(mat,word,i,j,0)) {
				return true;
			}
		}
	}
	return false;
}

int main () {
	char n;
	vector<vector<char>> vec;
	
}
*/

/////////////////////////////////////////////////////////////////////////
/*
 * 面试题11
 * 旋转数组
 */
/*
#include <iostream>
#include <vector>
using namespace std;

int MinInRotArray(vector<int> vec) {
	if (vec.size() == 1) return vec[0];
	int left = 0, right = vec.size() - 1;
	int mid = (left + right) / 2;
	while(left+1<right) { //中间有间隔
		mid = (left + right) / 2;
		if (vec[right] > vec[mid])
			right = mid;
		else if (vec[right] == vec[mid])
			right--;
		else
			left = mid;
	}
	return (vec[left] < vec[right]) ? vec[left] : vec[right];
}

int main() {
	vector<int> vec;
	int n;
	while (cin>>n) {
		vec.push_back(n);
		if (cin.get() == '\n')
			break;
	
		
	}
	int min = MinInRotArray(vec);
	system("pause");
	return 0;
}
*/


/*
 * 面试题10
 * 斐波那契数列
 * 简单题
 */
/*#include <iostream>
using namespace std;
int Febonacci(int n) {
	if (n == 1 || n == 2)
		return 1;
	else
		return Febonacci(n - 1) + Febonacci(n - 2);
}

int main() {
	int n;
	cin >> n;

	int sum=Febonacci(n);
	system("pause");
	return 0;
	
}*/


///////////////////////////////////////////////////////////////////
/*
 * 面试题9
 * 两个栈实现队列
 */
/*#include <iostream>
#include<stack>
using namespace std;

class MyQueue {
public:
	void MyPush(int val) {
		stk1.push(val);
	}

	int MyPop() {
		if(stk2.empty()) {
			while(!stk1.empty()) {
				int temp = stk1.top();
				stk2.push(temp);
				stk1.pop();
			}
		}
		int outdata = stk2.top();
		stk2.pop();
		return outdata;
	}
private:
	stack<int> stk1;
	stack<int> stk2;
};

int main() {
	MyQueue que;
	que.MyPush(1);
	que.MyPush(2);
	int a=que.MyPop();
	int b=que.MyPop();

	system("pause");
	return 0;
}*/



////////////////////////////////////////////////////////////////
/*
 * 面试题8
 * 二叉树的下一个节点
 * 不是很懂！！！！！！！！！！！！！！！！！！！！！！！！！！
 */
/*
#include<iostream>

struct TreeLinkNode {
	int val;
	TreeLinkNode *left;
	TreeLinkNode *right;
	TreeLinkNode *next;
	TreeLinkNode(int x) :val(x), left(nullptr), right(nullptr), next(nullptr) {};
};
using namespace std;

TreeLinkNode* GetNext(TreeLinkNode *p) {
	//右子树存在，那么中序遍历中，下一个节点就是右子树中最左边的点
	if(p->right) {
		p = p->right;
		while (p->left)
			p = p->next;
		return p;
	}
	//右子树不存在，只有左子树，左子树
	while(p->next) {
		//p不是根节点
		if (p == p->next->left)
			return  p->next;
		p = p->next;
	}
	
	return nullptr;
}

int main() {
	
}
*/






///////////////////////////////////////////////////////////////
/*
 * 面试题7
 * 重建二叉树
 */
/*#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

TreeNode* CreateTree(vector<int> pre,vector<int> vin) {
	if (pre.size() != vin.size() || pre.size() == 0||vin.size()==0)
		return nullptr;
	vector<int> pre_left;
	vector<int> pre_right;
	vector<int> vin_left;
	vector<int> vin_right;
	int j = 0;
	for(j;j<pre.size();j++) {
		if (pre[0] == vin[j])
			break;
	}
	TreeNode *proot = new TreeNode(pre[0]);
	for(int i=1;i<=j;i++) {
		pre_left.push_back(pre[i]);
		vin_left.push_back(vin[i - 1]);
	}
	for(int i=j+1;i<pre.size();i++) {
		pre_right.push_back(pre[i]);
		vin_right.push_back(vin[i]);
	}
	proot->left= CreateTree( pre_left, vin_left);
	proot->right= CreateTree( pre_right, vin_right);
	return proot;
}

int main() {
	// vector<int> pre;
	// vector<int> vin;
	// int number;
	// while(cin>>number) {
	// 	pre.push_back(number);
	// 	if (cin.get()=='\n') {
	// 		break;
	// 	}
	// }
	// while(cin>>number) {
	// 	vin.push_back(number);
	// 	if (cin.get() == '\n')
	// 		break;
	// }
	//
	// for(auto it=pre.begin();it!=pre.end();it++) {
	// 	cout << *it<<" ";
	// }
	// cout << endl;
	// for (auto it = vin.begin(); it != vin.end(); it++) {
	// 	cout << *it << " ";
	// }
	vector<int> pre1 = { 1,2,3,4,5,6,7 };
	vector<int> vin1 = { 3,2,4,1,6,5,7 };
	TreeNode *p = CreateTree(pre1, vin1);
	system("pause");
	return 0;
}*/


////////////////////////////////////////////////////////////////////////////////
/*
 * 面试题6
 * 从尾到头打印链表
 */
/*
 *#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;
struct  ListNode{      //定义一个链表
	int val;
	ListNode *next;
	ListNode(int x) :
		val(x), next(nullptr){}
};

ListNode* GetList(vector<int> vec) {    //将输入的数组转化为链表
	int length = vec.size();
	if (length < 1)
		return nullptr;
	ListNode* dumyhead = new ListNode(-1);
	ListNode* phead = dumyhead;
	for(int i=0;i<length;i++) {
		dumyhead->next = new ListNode(vec[i]);
		dumyhead = dumyhead->next;
	}
	return phead->next;
}

vector<int> ReturnReverse(ListNode* p) {
	vector<int> rlt;
	if (!p)
		return rlt;
	while(p) {
		rlt.push_back(p->val);
		p = p->next;
	}
	reverse(rlt.begin(), rlt.end());
	return rlt;
}

int main() {
	int n;
	vector<int> vec;
	while(cin>>n) {
		if (n == -1)
			break;
		vec.push_back(n);	
	}
	ListNode*head= GetList(vec);
	vector<int>rrlt= ReturnReverse(head);
	
	for(int i=0;i<vec.size();i++) {
		cout << vec[i] << " ";
	}  
	return 0;
}*/

/*--------------------------------------
 * 面试题5
 * 替换空格
 */
/*#include <iostream>
#include<string>
using namespace std;


int main() {
	string str;
	//cin >> str;
	getline(cin, str);
	string res;
	for(int i=0;i<str.size();i++) {
		if (str[i] != ' ')
			res += str[i];
		else
			res += "20%";
	}
	cout<<res;
	
//	system("pause");
	return 0;
}*/



/*------------------------------------------------
 * 面试题2
 * 有序二维数组的查找
 #1#
#include <iostream>
#include <vector>
using namespace std;

int number;
int row = 0;
int col=0;
bool Find(vector<vector<int>> matrix,int number) {
	int row = matrix.size();
	int col = matrix[0].size();
	int x = 0;
	int y = col - 1;
	bool flag = false;
	while (x<row && y>=0) {
		if(matrix[x][y]==number) {
			flag = true;
			break;
		}else if(matrix[x][y]>number) {
			--y;
		}else if(matrix[x][y]<number) {
			++x;
		}
	}
	return flag;
}

int main() {
	cin >> row >> col;
	vector<vector<int> > vecs(row, vector<int>(col));
	for (int i=0;i<row;i++) {
		for(int j=0;j<col;j++) {
			cin >> vecs[i][j];
		}
	}
	cin >> number;
	Find(vecs, number);
	return 0;
	system("pause");
}*/

/*#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
#include <unordered_map>

using namespace  std;*/
/*
//#include <stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left = NULL;
	TreeNode* right = NULL;
	TreeNode(int val) : val(val), left(NULL), right(NULL) {}
};

void create(TreeNode **root) {
	int num;
	cin >> num;
	if (num == -1) return;
	*root = new TreeNode(num);
	create(&((*root)->left));
	create(&((*root)->right));
}

void print(TreeNode* root) {
	if (!root) {
		cout << -1 << " ";
		return;
	}
	cout << root->val << " ";
	print(root->left);
	print(root->right);
}

int main() {
	TreeNode *root = nullptr;
	create(&root);
	print(root);
	return 0;
}*/
////////////////////////////////////////////////////////////////////////////////////
/*
 * 贪心算法，计算孩子与饼干
 *int num1;
	cin >> num1;
	vector<int> children(num1);
	for (int i = 0; i<num1; i++) {
		cin >> children[i];
	}
	cout << "done" << endl;
	int num2;
	cin >> num2;
	vector<int> cookies(num2);
	for(int j=0;j<num2;j++) {
		cin >> cookies[j];
	}
	return findContentChildren(children, cookies);

 */
/*int findContentChildren(vector<int>children,vector<int>cookies) {
	sort(children.begin(), children.end());
	sort(cookies.begin(), cookies.end());
	int child = 0;
	int cookie = 0;
	while (child<children.size() && cookie<cookies.size()) {
		if (children[child]<=cookies[cookie]) {
			++child;
		}
		++cookie;
	}
	return child;
}*/
////////////////////////////////////////////////
////////////////////////////////////////////////

/*
 * -----贪心算法：糖果-----
 * 	int n;
	cin >> n;
	vector<int> vec(n);
	for (int i=0;i<n;i++) {
		cin >> vec[i];
	}
	
	//vector<int> vec = { 1,0,2 };
	Candy(vec);
 */
/*int Candy(vector<int> vec) {
	vector<int> candies(vec.size(),1);
	for (int i=0;i<vec.size()-1;i++) {
		if (vec[i]<vec[i+1]) {
			candies[i + 1]=candies[i]+1;
		}
	}
	for(int i=vec.size()-1;i>0;i--) {
		if (vec[i]<vec[i-1]) {
			candies[i - 1]=candies[i]+1;
		}
	}
	int sum = 0;
	for (int i=0;i<candies.size();i++) {
		sum += candies[i];
	}
	return sum;
}*/

///////////////////////////////////////////////
///////////////////////////////////////////////
/*
 *面试题3
 * -----数组中的重复数字--------
 */
/*int FindDuplicate(vector<int> vec) {
	// vector<int> ::iterator it;
	unordered_map<int,int> umap;
	for (int i=0;i<vec.size();i++) {
		umap[vec[i]]++;
		if (umap[vec[i]]>1) {
			return vec[i];
		}
	}
	return -1;
}


int main() {
	int n;
	cin >> n;
	vector<int> vec(n);
	for(int i=0;i<n;i++) {
		cin >> vec[i];
	}
	FindDuplicate(vec);
	system("pause");
}*/


/*
 * 计算一个无序数组最多有几个有序排列的方式
 */
/*int main() {
	int n;
	cin >> n;
	vector<int> vec(n);
	
	int count=0;
	
	for (int i = 0; i < n; i++)
		cin >> vec[i];
	int j = 0;
	while(j<n) {
		if(vec[j]<vec[j+1]) {
			while (j + 1 < n && vec[j] < vec[j + 1])
				j++;
			j++;
			count++;
		}
		else if (vec[j] == vec[j + 1])
			j++;
		else {
			while (j+1<n && vec[j]>vec[j + 1])
				j++;
			j++;
			count++;
		}
	}
	cout << count << endl;
	system("pause");
}*/




/*
 * 判断是不是2的指数
 * 按位与，右移操作
 */
/*int a[55];
int main() {
	int n;
	cin >> n;
	for(int i=0;i<n;i++) {
		cin >> a[i];
	}
	for(int j=0;j<n;j++) {
		cout << a[j] << " ";
	}
	string res = "YES";
	for(int k=0;k<n;k++) {
		while (!(a[k] & 1))
			a[k] >>= 1;
	}
	for(int i=0;i<n;i++) {
		if (a[i] != a[0])
			res = "NO";
	}
	cout << res << endl;
	system("pause");
}*/