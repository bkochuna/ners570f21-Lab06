# content of test_BCRS.py
from SpMVpy import BCRS


def test_constructor():
    A = BCRS(10, 10)
    assert A.getnRows() == 10
    assert A.getnCols() == 10
    assert A.getnNZ() == 0
