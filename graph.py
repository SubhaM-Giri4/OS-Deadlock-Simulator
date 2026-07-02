import networkx as nx
import matplotlib.pyplot as plt

def show_graph():
    g = nx.DiGraph()
    g.add_edge("P1","P2")
    g.add_edge("P2","P3")
    g.add_edge("P3","P1")

    pos = nx.circular_layout(g)
    nx.draw(g,pos,with_labels=True,node_size=3000)
    plt.title("Wait For Graph")
    plt.show()
