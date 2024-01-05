#include<bits/stdc++.h>
using namespace std;
struct Node;  // 前向声明

typedef struct Node
{
    char data;
    Node *lchild;
    Node *rbro;
} Node;

Node* createNode(char data){
     Node *node=(Node *)malloc(sizeof(Node));
     node->data=data;
     node->lchild=NULL;
     node->rbro=NULL;
     return node;
}

void xian(Node *node){
    if(node!=NULL){
    cout<<node->data;
    xian(node->lchild);
    xian(node->rbro);
    }
        
    return ;
}

void hou (Node *node){
    if(node!=NULL){
        hou(node->lchild);
        cout<<node->data;
        hou(node->rbro);

    }
    
    return ;
}
int calculateDepthOfLevelOrder(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    queue<Node*> q;
    q.push(root);
    int depth = 0;

    while (!q.empty()) {
        int levelSize = q.size();

        for (int i = 0; i < levelSize; i++) {
            Node* curr = q.front();
            q.pop();

            // 你可以在这里处理每个节点的数据，如果需要的话

            Node* child = curr->lchild;
            while (child) {
                q.push(child);
                child = child->rbro;
            }
        }

        depth++;
    }

    return depth ;
}

int cnt;
void countLeafNodes(Node* root) {
    if (root == nullptr) {
        cnt+=0;
    }
    if (root->lchild == nullptr) {
        cnt+=1;
    }
     if (root->lchild != nullptr) {
        countLeafNodes(root->lchild) ;
    }
    
    if (root->rbro != nullptr) {
        countLeafNodes(root->rbro) ;
    }
}
string removeLastChar(const string& s) {
    int length = s.length();

    if (length >= 1) {
        return s.substr(0, length - 1);
    } else {
        return "";
    }
}
void zimu(string s,Node *node){

    s=s+node->data;

    if(node->lchild!=NULL){
        zimu(s,node->lchild);
    }
    else{
        cout<<s<<endl;
    }
    if(node->rbro!=NULL){
        string temp=removeLastChar(s);
        zimu(temp,node->rbro);
    }
}



//  cengci(Node *node){
    
//     q.push(node);
//     if(node->rbro!=NULL)
//     cengci(node->rbro);
//     if(node->lchild!=NULL){
//         q.push(node->lchild);
//     }


    
    
// }
void levelOrde(Node* root)
   {
      queue<Node*> q;
      q.push(root);

      while(!q.empty())
      {
                  root=q.front();q.pop();
                  cout<<root->data;
                //   cout<<"++"<<endl;
                  root=root->lchild;
                  while(root)
                  {
                      q.push(root);
                      root=root->rbro;
                   }
      }
   }
int main(){
    Node *root,*temp;
    char pre,last;
    queue<Node *> dl;
    int flag=0;
    string s;
            getline(cin,s);
            pre=s[0];
            last=s[2];
            root=createNode(last);
            dl.push(root);
    while(1){
        if(flag==0){
            string s;
            getline(cin,s);
            pre=s[0];
            last=s[2];
            // cout<<"=="<<endl;
        }
        if(pre=='#' && last=='#'){
            // cout<<"===";
            xian(root);
            cout<<endl;
            hou(root);
            cout<<endl;
            levelOrde(root);
            cout<<endl;
            cout<<calculateDepthOfLevelOrder(root)<<endl;
            countLeafNodes(root);
            cout<<cnt<<endl;
            zimu("",root);
                return 0;
        }
            Node *nw=createNode(last);
            Node *tp=dl.front();
            char tpdt=tp->data;
            // cout<<tpdt<<"++"<<endl;
            
            if(tpdt==pre){
                dl.push(nw);
                tp->lchild=nw;
                // cout<<nw->data<<endl;
                while(1){
                    string is;
                    getline(cin,is);
                    char prein=is[0];
                    char lastin=is[2];
                    if(prein!=tpdt){
                        pre=prein;
                        last=lastin;
                        flag=1;
                        break;
                    }
                    else{   temp=dl.back();
                            Node *nwin=createNode(lastin);
                            // Node *tp=dl.front();
                            dl.push(nwin);
                            temp->rbro=nwin;
                    }
                }
            }
            dl.pop();
}

}