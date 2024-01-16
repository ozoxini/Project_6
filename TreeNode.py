# TreeNode.py
class TreeNode:
    def __init__(self, value):
        self.value = value
        self.children = {}

    def add_child(self, key, child):
        self.children[key] = child

    def get_child(self, key):
        return self.children.get(key)

    def get_children(self):
        return self.children.values()