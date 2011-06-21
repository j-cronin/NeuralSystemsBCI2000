import numpy

#################################################################
#################################################################

class BciSource(BciGenericSource):	

	#############################################################

	def Construct(self):
		parameters = [
		]
		states = [
		]
		return (parameters, states)

	#############################################################

	def Initialize(self, indim, outdim):
		pass
		
	#############################################################

	def Process(self, sig):
		return 2000.0 * numpy.sin(2.0 * 5.0 * numpy.pi * sig)

	#############################################################

	def StopRun(self):
		pass
		
#################################################################
#################################################################
