# -*- coding: utf-8 -*-
# Copyright (C) 2023 by iamslash 

import pandas as pd

# 472ms 100.00% 59.8MB 100.00%
def findHeavyAnimals(animals: pd.DataFrame) -> pd.DataFrame:
    animals = animals.sort_values(by='weight', ascending=False)
    return animals.loc[animals['weight'] > 100, ['name']]
