typedef struct trie{

    typedef struct node{
        node* nxt[2];
        int cnt = 0;
        node(){
            nxt[0] = nxt[1] = NULL;
            cnt = 0;
        }
    }Node;
    
    Node* head;
    trie(){ 
        head = new Node();
    }
    void insert(int x){
        Node* curr = head;
        for(int i=30;i>=0;i--){
            int b = (x>>i)&1;

            if(curr->nxt[b] == NULL){
                curr->nxt[b] = new Node();
            }
            curr = curr->nxt[b];
            curr->cnt ++;
        }
    }
    void remove(int x){

        Node* curr = head;
        for(int i=30;i>=0;i--){
            int b = (x>>i)&1;
            curr = curr->nxt[b];
            curr->cnt --;

        }    
    }
    
}Trie;