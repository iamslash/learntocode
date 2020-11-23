# -*- coding: utf-8 -*-
# Copyright (C) 2020 by iamslash

# Time Limit Exceeded
# BFS, lock
# O(N) O(N)
import threading
from queue import Queue
class Solution:
	def crawl(self, startUrl: str, htmlParser: 'HtmlParser') -> List[str]:			
		def getHostname(url):
			return url.replace("http://", "").split('/')[0]
		bfsq = Queue()
		seen = {startUrl}
		startHostname = getHostname(startUrl)
		lock = threading.Lock()		
		def worker():
			while True:
				uUrl = bfsq.get()
				if uUrl is None:
					return
				for vUrl in htmlParser.getUrls(uUrl):
					if vUrl not in seen and getHostname(vUrl) == startHostname:
						lock.acquire()
						if vUrl not in seen:
							seen.add(vUrl)
							bfsq.put(vUrl)
						lock.release()
				bfsq.task_done()
					
		numWorkers = 8
		workers = []
		bfsq.put(startUrl)

		# make thread pool
		for i in range(numWorkers):
			t = threading.Thread(target=worker)
			t.start()
			wokers.append(t)

		bfsq.join()
		for i in range(numWorkers):
			bfsq.put(None)
		for t in workers:
			t.join()

		return list(seen)		

def main():
	pass

if __name__ == "__main__":
	main()
