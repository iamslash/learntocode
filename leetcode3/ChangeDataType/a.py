# -*- coding: utf-8 -*-
# Copyright (C) 2023 by iamslash 

import pandas as pd

# 467ms 100.00% 60.8MB 100.00%
def changeDatatype(students: pd.DataFrame) -> pd.DataFrame:
    return students.astype({'grade': 'int'})

