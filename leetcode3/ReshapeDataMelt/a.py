# -*- coding: utf-8 -*-
# Copyright (C) 2023 by iamslash 

import pandas as pd

# 485ms 100.00% 60.8MB 100.00%
def meltTable(report: pd.DataFrame) -> pd.DataFrame:
    return pd.melt(report, id_vars=['product'], var_name='quarter', value_name='sales')

