# content of test_JDS.py
from SpMVpy import JDS


def test_constructor():
    A = JDS(10, 10)
    assert A.getnRows() == 10
    assert A.getnCols() == 10
    assert A.getnNZ() == 0
