# content of test_COO.py
from SpMVpy import COO


def test_constructor():
    A = COO(10, 10)
    assert A.getnRows() == 10
    assert A.getnCols() == 10
    assert A.getnNZ() == 0
