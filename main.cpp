#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void PrintList(ListNode **l){
    if(*l == nullptr){
        return;
    }
    ListNode *p = (*l);
    while(p != nullptr){
        cout<<p->val<<" \t";
        p = p->next;
    }
    cout<<endl;
}

void AddHead(ListNode **l, ListNode *temp)
{
    if ((*l) == nullptr) {
        (*l) = temp;
    } else {
        temp->next = (*l);
        (*l) = temp;
    }
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0;
        ListNode *rs = nullptr;
        ListNode *tail = nullptr;
        while(l1 || l2 || sum>0){
            if(l1)
            {
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2)
            {
                sum+=l2->val;
                l2=l2->next;
            }
            ListNode *temp = new ListNode(sum%10);
            sum /= 10;
            if(!rs){
                tail = temp;
                rs = tail;
            }else{
                tail->next = temp;
                tail = temp;
            }
        }
        return rs;
    }
};
int main(){
    auto *s = new Solution();
    int A[3] = {2,4,3};
    int B[3] = {5,6,4};
    ListNode *a = nullptr;
    for (int i=2; i>=0; i--) {
        AddHead(&a, new ListNode(A[i]));
    }
    PrintList(&a);
    ListNode *b = nullptr;
    for (int i=2; i>=0; i--) {
        AddHead(&b, new ListNode(B[i]));
    }
    PrintList(&b);
    ListNode *z = s->addTwoNumbers(a,b);
    PrintList(&z);
    return 0;
}