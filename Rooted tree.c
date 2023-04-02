#define NULL_VALUE -1
#define SUCCESS_VALUE 1

struct tree_node
{
    int item; // stores the item
    struct tree_node * left_child; // points to left child
    struct tree_node * right_child; // points to right child
};

struct tree_node *root ; //global variable to store tree

void initialize_tree()
{
    root = 0 ;
}

struct tree_node *search_item(struct tree_node *node, int item)
{
    if ( node == 0 ) return 0;

    // check if item is matched with this node
    if ( node->item == item ) return node ;

    // search the left_child subtree rooted at left_child child
    struct tree_node * t ;
    t = searchItem(node->left_child, item) ;
    if (t != 0) return t ;

    // search the right_child subtree rooted at right_child child
    t = searchItem(node->right_child, item) ;
    if (t != 0) return t ;

    // finally, return NULL because item was not found
    return 0 ;
}



int insert_item(struct tree_node * node, int oldItem, int newItem, int childType)
{
    if ( node == 0 ) return 0 ;
    //check if item is matched with this node
    if ( node->item == oldItem )
    {
        if( childType==left_child && node->left_child==0 )
        {
            struct tree_node * newNode ;
            newNode = (struct tree_node*)malloc(sizeof(struct tree_node));
            newNode->item = newItem ;
            newNode->left_child = 0 ;
            newNode->right_child = 0 ;
            node->left_child = newNode ;
            return 1;
        }
        else if( childType==right_child && node->right_child==0 )
        {
            struct tree_node * newNode ;
            newNode->item = newItem ;
            newNode->left_child = 0 ;
            newNode->right_child = 0 ;
            node->right_child = newNode ;
            return 1;
        }
        else return FALSE_VALUE ;

    }

    //search the left_child sub-tree for possible insertion
    int t;
    t = insert_item(node->left_child, oldItem, newItem, childType) ;
    if (t == TRUE_VALUE) return t ;

    //search the right_child sub-tree for possible insertion
    t = insert_item(node->right_child, oldItem, newItem, childType) ;
    if (t == TRUE_VALUE) return t ;

    //finally, return NULL because item was not found
    return FALSE_VALUE ;
}

int insert_root(int item)
{
    struct tree_node * newNode ;
    newNode = (struct tree_node*)malloc(sizeof(struct tree_node)) ;
    newNode->left_child = 0 ;
    newNode->right_child = 0 ;
    root = newNode ;
    return TRUE_VALUE ;
}



void print_tree_preorder(struct tree_node * node)
{
    if ( node == 0 ) return 0 ;
    print(“%d ”, node->item) ;
    print_tree_preorder(node->left_child) ;
    print_tree_preorder(node->right_child) ;
}
void print_tree_inorder(struct tree_node * node)
{
    if ( node == 0 ) return 0 ;
    print_tree_inorder(node->left_child) ;
    print(“%d ”, node->item) ;
    print_tree_inorder (node->right_child) ;
}
void print_tree_postorder(struct tree_node * node)
{
    if ( node == 0 ) return 0 ;
    print_tree_postorder(node->left_child) ;
    print_tree_postorder(node->right_child) ;
    print(“%d ”, node->item) ;
}
