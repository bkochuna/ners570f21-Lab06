# content of test_CRS.py
from SpMVpy import CRS


def test_constructor():
    A = CRS(10, 10)
    assert A.getnRows() == 10
    assert A.getnCols() == 10
    assert A.getnNZ() == 0
