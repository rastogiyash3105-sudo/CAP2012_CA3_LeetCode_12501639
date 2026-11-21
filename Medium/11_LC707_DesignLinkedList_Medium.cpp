class MyLinkedList {
public:
    struct Node {
        int val;
        Node* next;
        Node(int x) {
            val=x;
            next=NULL;
        }
    };
    Node* head;
    int size;
    MyLinkedList() {
        head=NULL;
        size=0;
    }
    int get(int index) {
        if(index<0 || index>=size)
            return -1;
        Node* temp=head;
        for(int i=0;i<index;i++)
            temp=temp->next;
        return temp->val;
    }
    void addAtHead(int val) {
        Node* temp=new Node(val);
        temp->next=head;
        head=temp;
        size++;
    }
    void addAtTail(int val) {
        Node* temp=new Node(val);
        if(head==NULL)
            head=temp;
        else {
            Node* curr=head;
            while(curr->next!=NULL)
                curr=curr->next;
            curr->next=temp;
        }
        size++;
    }
    void addAtIndex(int index,int val) {
        if(index<0 || index>size)
            return;
        if(index==0) {
            addAtHead(val);
            return;
        }
        Node* curr=head;
        for(int i=0;i<index-1;i++)
            curr=curr->next;
        Node* temp=new Node(val);
        temp->next=curr->next;
        curr->next=temp;
        size++;
    }
    void deleteAtIndex(int index) {
        if(index<0 || index>=size)
            return;
        Node* temp;
        if(index==0) {
            temp=head;
            head=head->next;
        }
        else {
            Node* curr=head;
            for(int i=0;i<index-1;i++)
                curr=curr->next;
            temp=curr->next;
            curr->next=temp->next;
        }
        delete temp;
        size--;
    }
};
