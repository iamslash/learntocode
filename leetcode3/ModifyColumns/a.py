# -*- coding: utf-8 -*-
# Copyright (C) 2023 by iamslash 

import pandas as pd

# 445ms 100.00% 59.4MB 100.00%
def modifySalaryColumn(employees: pd.DataFrame) -> pd.DataFrame:
    employees['salary'] *= 2
    return employees
