# -*- coding: utf-8 -*-
# Copyright (C) 2023 by iamslash 

import pandas as pd

# 453ms 100.00% 59.5MB 100.00%
def selectFirstRows(employees: pd.DataFrame) -> pd.DataFrame:
    return employees.head(3)
