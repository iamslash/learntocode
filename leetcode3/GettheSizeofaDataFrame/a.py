# -*- coding: utf-8 -*-
# Copyright (C) 2023 by iamslash 

import pandas as pd

# 453ms 100.00% 60.4MB 100.00%
def getDataframeSize(players: pd.DataFrame) -> List[int]:
    return list(players.shape)
