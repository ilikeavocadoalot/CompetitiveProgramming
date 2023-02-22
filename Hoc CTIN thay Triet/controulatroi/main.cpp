#include <iostream>
#include <stack>




using namespace std;




/*
4 (
3 )
2 * / %
1 + -
0


*/






struct Node{
    Node(){
        nodeType = 0;
        op = "";
        value = 0;
        left = NULL;
        right = NULL;
    };//default contructor
    Node(int iNodeType, string sOp, int iValue, int iLevel, Node *pleft, Node *pright){
        nodeType = iNodeType ; //neu 0 Operator, 1: Operand
        op = sOp;
        value = iValue;
        level = iLevel;
        left = pleft;
        right = pright;
    }
    int nodeType ; //neu 0 Operator, 1: Operand
    string op;
    int value;
    int level;
    Node *left,*right;
};


stack <Node> OprStack, NodeStack;




int getLevel(string s){
    if(s=="(")
        return 4;
    else  if(s==")")
        return 3;
    else  if(s=="*" || s=="/" || s=="%")
        return 2;
    else  if(s=="+" || s=="-")
        return 1;
    else
        return 0;
}


/*
Day dinh cua OpsStack ra lam goc
Canh phai chi ve dinh cua NodeStack
Pop NodeStack
Canh trai chi ve dinh cua NodeStack
Pop Nodestack


*/


int CreateSubTree(){
    //tao moi mot node va lay gia tri cua node dang o dinh OprStack dat vao do
    Node nOpr = (Node) OprStack.top();
    //Pop dinh OprStack
    OprStack.pop();


    //Node n2 = NodeStack.top();
    //tao vung nho dong
    Node *n2 = new Node(); //new==> mot dia chi// dia chi cua o nho bat dau cua vung nho do
    (*n2) = NodeStack.top();
    NodeStack.pop();


    //ode n1 = NodeStack.top();
    Node *n1 = new Node();
    (*n1) = NodeStack.top();
    NodeStack.pop();
    nOpr.left = n1;
    nOpr.right = n2;
    NodeStack.push(nOpr);
}


int duyetInfix(Node * root){


    if(root->left != NULL)
        duyetInfix(root->left);
    if(root->nodeType == 0)
        cout<< root->op;
    else
        cout<< root->value;
    if(root->right != NULL)
        duyetInfix(root->right);
}
int cong(int a, int b){
    int c= a+ b;
    return c;
}




int main()
{
    freopen("CONGTHUC.INP","r",stdin);
    freopen("CONGTHUC.OUT","w",stdout);






    string s;
    while (cin>>s){
        int level = getLevel(s);


        int v;
        if(level == 4){//Neu la ( => day no vao OprStack
            Node node(0,s,0,level,NULL,NULL);
            OprStack.push(node);
        }
        else if (level == 0){ // cac toan hang => Node
            string::size_type sz;
            int val = stoi(s,&sz);
            Node node(1,"",val,level,NULL,NULL);
            NodeStack.push(node);
        }
        else if (level == 3){ // s ==")"  //lap lai cho den khi nao dung den (
            Node node = OprStack.top();//Lay node ngay dau OprStack de kiem tra
            while(node.op != "("){
                CreateSubTree();
                node = OprStack.top();
            }
            OprStack.pop();//Day node ( ra khoi OprStack
        }
        else if (level == 2 || level == 1){//-+(-
                                                    //node * + /
            if(!OprStack.empty()  ){
                Node node = OprStack.top();
                while (!OprStack.empty() && node.op !=  "(" && node.level>= level){
                    CreateSubTree();
                    node = OprStack.top();
                }
                //OprStack.pop();
            }
            Node newOp (0,s,0,level,NULL,NULL);
            OprStack.push(newOp);
        }
    }


    while(!OprStack.empty()){
        CreateSubTree();
    }


    duyetInfix(&NodeStack.top());
    return 0;
}
