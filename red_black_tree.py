RED=0
BLACK=1

def left_rotate(tree,node):
    if node.right==None:
        return False
    node_right=node.right
    node_right.parent=node.parent
    if not node.parent:
        tree.root=node_right
    elif node==node.parent.left:
        node.parent.left=node_right
    else:
        node.parent.right=node_right
    if node_right.left:
        node_right.left.parent=node
    node.right=node_right.left
    node.parent=node_right
    node_right.left=node

def right_rotate(tree,node):
    if node.left==None:
        return False
    node_left=node.left
    node_left.parent=node.parent
    if not node.parent:
        tree.root=node_left
    elif node==node.parent.left:
        node.parent.left=node_left
    else:
        node.parent.right=node_left
    if node_left.right:
        node_left.right.parent=node
    node.left=node_left.right
    node.parent=node_left
    node_left.right=node

def transplant(tree,node_u,node_v):
    if not node_u.parent:
        tree.root=node_v
    elif node_u==node_u.parent.left:
        node_u.parent.left=node_v
    else:
        node_u.parent.right=node_v
    if node_v:
        node_v.parent=node_u.parent


def tree_maximum(node):
    temp_node=node
    while temp_node.right:
        temp_node=temp_node.right
    return temp_node


def tree_minimum(node):
    temp_node=node
    while temp_node.left:
        temp_node=temp_node.left
    return temp_node


def preorder_tree_walk(node):
    if node:
        print(node.value,node.color)
        preorder_tree_walk(node.left)
        preorder_tree_walk(node.right)

class RedBlackTreeNode(object):
    def __init__(self,value):
        self.value=value
        self.left=None
        self.right=None
        self.parent=None
        self.color=RED

class RedBlackTree(object):
    def __init__(self):
        self.root=None

    def insert(self,node):
        temp_root=self.root
        temp_node=None
        while temp_root:
            temp_node=temp_root
            if node.value==temp_node.value:
                return False
            elif node.value>temp_node.value:
                temp_root=temp_root.right
            else:
                temp_root=temp_root.left
        if not temp_node:
            self.root=node
            node.color=BLACK
        elif node.value<temp_node.value:
            temp_node.left=node
            node.parent=temp_node
        else:
            temp_node.right=node
            node.parent=temp_node
        self.insert_fixup(node)

    def insert_fixup(self,node):
        if node.value==self.root.value:
            return
        while node.parent and node.parent.color==RED:
            if node.parent==node.parent.parent.left:
                node_uncle=node.parent.parent.right
                if node_uncle and node_uncle.color==RED:
                    node.parent.color=BLACK
                    node_uncle.color=BLACK
                    node.parent.parent.color=RED
                    node=node.parent.parent
                    continue
                elif node==node.parent.right:
                    left_rotate(self,node.parent)
                    node=node.left
                node.parent.color=BLACK
                node.parent.parent.color=RED
                right_rotate(self,node.parent.parent)
                return
            elif node.parent==node.parent.parent.right:
                node_uncle=node.parent.parent.left
                if node_uncle and node_uncle.color==RED:
                    node.parent.color=BLACK
                    node_uncle.color=BLACK
                    node.parent.parent.color=RED
                    node=node.parent.parent
                    continue
                elif node==node.parent.left:
                    right_rotate(self,node.parent)
                    node=node.right
                node.parent.color=BLACK
                node.parent.parent.color=RED
                left_rotate(self,node.parent.parent)
                return

        self.root.color=BLACK
                
    def delete(self,node):
        node_color=node.color
        if not node.left:
            temp_node=node.right
            transplant(self,node,node.right)
        elif not node.right:
            temp_node=node.left
            transplant(self,node,node.left)
        else:
            node_min=tree_minimum(node.right)
            node_color=node_min.color
            temp_node=node_min.right
            if node_min.parent!=node:
                transplant(self,node_min,node_min.right)
                node_min.right=node.right
                node_min.right.parent=node_min
            transplant(self,node,node_min)
            node_min.left=node.left
            node_min.left.parent=node_min
            node_min.color=node.color
        if node_color==BLACK:
            self.delete_fixup(temp_node)

    def delete_fixup(self,node):
        while node!=self.root and node.color==BLACK:
            if node==node.parent.left:
                node_brother=node.parent.right
                if node_brother.color==RED:
                    node_brother.color=BLACK
                    node.parent.color=RED
                    left_rotate(self,node.parent)
                    node_brother=node.parent.right
                if (not node_brother.left or node_brother.left.color==BLACK) and (not node_brother.right or node_brother.right.color==BLACK):
                    node_brother.color=RED
                    node=node.parent
                else:
                    if not node_brother.right or node_brother.right.color==BLACK:
                        node_brother.color=RED
                        node_brother.left.color=BLACK
                        right_rotate(self,node_brother)
                        node_brother=node.parent.right
                    node_brother.color=node.parent.color
                    node.parent.color=BLACK
                    node_brother.right.color=BLACK
                    left_rotate(self,node.parent)
                node=self.root
                break
            else:
                node_brother=node.parent.left
                if node_brother.color==RED:
                    node.brother.color=BLACK
                    node.parent.color=RED
                    left_rotate(self,node.parent)
                    node_brother=node.parent.right
                if(not node_brother.left or node_brother.left.color==BLACK) and (not node_brother.right or node_brother.right.color==BLACK):
                    node_brother.color=RED
                    node=node.parent
                else:
                    if not node_brother.left or node_brother.left.color==BLACK:
                        node_brother.color=RED
                        node_brother.right.color=BLACK
                        left_rotate(self,node_brother)
                        node_brother=node.parent.left
                    node_brother.color=node.parent.color
                    node.parent.color=BLACK
                    node_brother.left.color=BLACK
                    right_rotate(self,node.parent)
                node=self.root
                break
        node.color=BLACK

    

def main():
    number_list={7,4,1,8,5,2,9,6,3}
    tree=RedBlackTree()
    for number in number_list:
        node=RedBlackTreeNode(number)
        tree.insert(node)
        del node
    preorder_tree_walk(tree.root)
    tree.delete(tree.root)
    preorder_tree_walk(tree.root)

if __name__=="__main__":
    main()