# -*- coding: utf-8 -*-
# Copyright (C) 2023 by iamslash 

import pandas as pd

# 507ms 100.00% 60.9MB 100.00%
def dropDuplicateEmails(customers: pd.DataFrame) -> pd.DataFrame:
    return customers.drop_duplicates(subset=['email'])
