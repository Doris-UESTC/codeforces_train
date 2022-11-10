
from random import shuffle
import random

root_node = None

_M = 5


class Logger(object):
    @classmethod
    def tree(cls, node, child_name, dsc, depth):
        if depth == 0:
            head = "|   " * depth
            print(head + "+--" + dsc(node))
            depth = depth + 1

        for child in getattr(node, child_name):
            head = "|   " * depth
            print(head + "+--" + dsc(child))
            cls.tree(child, child_name, dsc, depth + 1)


class BKeyword(object):
    def __init__(self, key, data):
        self.key = key
        self.data = data


class BNode(object):
    def __init__(self):
        self._parent: BNode = None
        self.keywords = []
        self.child_nodes = []

    # 设置父节点
    def set_parent(self, node):
        self._parent = node
        if node.get_parent() is None:
            global root_node
            root_node = node.get_parent()

    # 获取父节点
    def get_parent(self):
        return self._parent

    # 添加子节点到指定位置
    def insert_child_node(self, index, add_node):
        add_node.set_parent(self)
        self.child_nodes.insert(index, add_node)

    # 添加子节点
    def append_child_node(self, add_node):
        add_node.set_parent(self)
        self.child_nodes.append(add_node)

    # 找到合适的插入点
    def find_add_index(self, add_word):
        if len(self.keywords) == 0:
            return 0
        index = 0
        while True:
            if index >= len(self.keywords):
                break
            key = self.keywords[index].key
            if add_word.key < key:
                break
            index = index + 1
        return index

    # 盲插，无论是否超出M值，先插入数据到合适位置
    def blind_add(self, word: BKeyword) -> int:
        index = self.find_add_index(word)
        self.keywords.insert(index, word)

    # 分裂
    def split(self):
        # 分裂节点
        parent, center_keyword, left_node, right_node = self.split_to_piece()
        # 添加分类后的两个新节点到父节点，并建立关系
        parent_add_index = parent.find_add_index(center_keyword)
        parent.insert_child_node(parent_add_index, right_node)
        parent.insert_child_node(parent_add_index, left_node)
        # 移除自身（包含M个关键字）
        if self in parent.child_nodes:
            parent.child_nodes.remove(self)
        # 注意：先解决子节点再解决父节点，否则会出问题
        parent.add_word(center_keyword, force=True)
        # 重新定义根结点
        root = self
        while root.get_parent() is not None:
            root = root.get_parent()
        global root_node
        root_node = root

    # 分裂成碎片
    def split_to_piece(self):
        center_keyword = self.keywords[int((_M-1)/2)]
        if self.get_parent() is None:
            self.set_parent(BNode())
        left_node = BNode()
        right_node = BNode()
        for keyword in self.keywords:
            if keyword.key < center_keyword.key:
                left_node.keywords.append(keyword)
            elif keyword.key > center_keyword.key:
                right_node.keywords.append(keyword)
        for i in range(len(self.child_nodes)):
            if i <= int((len(self.child_nodes) - 1)/2):
                left_node.append_child_node(self.child_nodes[i])
            else:
                right_node.append_child_node(self.child_nodes[i])
        return self.get_parent(), center_keyword, left_node, right_node

    # 新增关键字，force表示是否进位。默认添加到叶子结点，进位添加为直接添加，需要分裂则继续往父节点增加关键字。方向完全相反。
    def add_word(self, keyword, force=False):
        if keyword.key == 0:
            print("")
        # 叶子节点 或 进位添加
        if len(self.child_nodes) == 0 or force:
            if keyword.key == 20:
                print("")
            self.blind_add(keyword)
            if len(self.keywords) == _M:
                # 开始分裂
                print("新增:" + str(keyword.key) + ", 达到m值，分裂")
                self.split()
        else:
            # 非叶子节点
            index = self.find_add_index(keyword)
            if index >= len(self.child_nodes):
                index = index - 1
            self.child_nodes[index].add_word(keyword)


def print_tree(node):

    print("\n******************************")

    def dsc(node):
        s = ''
        for keyword in node.keywords:
            s = s + str(keyword.key) + ','
        # 打印内存地址
        # s = s + '[' + str(id(node)) + ']'
        s = s[:-1]
        return s
    Logger.tree(node, 'child_nodes', dsc,  0)
    print("******************************")


def prepare():
    array = []
    number = 0
    for i in range(200):
        number = number + random.randint(1, 4)
        # number = number + 1
        array.append(number)
    shuffle(array)
    return array


if __name__ == '__main__':
    root_node = BNode()
    array = prepare()
    for i in array:
        keyword = BKeyword(i, "数据" + str(i))
        root_node.add_word(keyword)
    print_tree(root_node)