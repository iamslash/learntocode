# -*- coding: utf-8 -*-
# Copyright (C) 2023 by iamslash 

import pandas as pd

# 632ms 100.00% 61MB 100.00%
def dropMissingData(students: pd.DataFrame) -> pd.DataFrame:
    return students.dropna()
