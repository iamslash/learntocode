# -*- coding: utf-8 -*-
# Copyright (C) 2023 by iamslash 

import pandas as pd

# 449ms 100.00% 59.5MB 100.00%
def fillMissingValues(products: pd.DataFrame) -> pd.DataFrame:
    products["quantity"] = products["quantity"].fillna(0)
    return products
    
