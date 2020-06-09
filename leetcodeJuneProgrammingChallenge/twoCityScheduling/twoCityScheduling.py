# https://leetcode.com/problems/two-city-scheduling/

############################## Description: ##############################
# There are 2N people a company is planning to interview. 
# The cost of flying the i-th person to city A is costs[i][0],
# and the cost of flying the i-th person to city B is costs[i][1].
# Return the minimum cost to fly every person to a city such that
# exactly N people arrive in each city.

class Solution(object):
    def twoCitySchedCost(self, costs):
        """
        :type costs: List[List[int]]
        :rtype: int
        """
        # Get savings
        savings = self.getSavings(costs)
        
        # Get map of people associated with savings
        personBySavings = self.getPersonBySavings(savings, costs)
        
        # Sort savings in descending order
        savingsKeySet = personBySavings.keys()
        savingsKeySet.sort(reverse=True)
                
        return self.getMinCost(savingsKeySet, personBySavings, len(costs)/2)
        
    def getSavings(self, costs):
        savings = []
        for i in range (len(costs)):
            p = costs[i]
            savings.append(abs(p[0] - p[1]))
        return savings
    
    def getPersonBySavings(self, savings, costs):
        personBySavings = {}
        for i in range(len(savings)):
            if savings[i] in personBySavings:
                personBySavings[savings[i]].append(costs[i])
            else:
                personBySavings[savings[i]] = [costs[i]]
                
        return personBySavings
    
    def getMinCost(self, savings, personBySavings, N):
        A = []
        B = []
        for saving in savings:
            people = personBySavings[saving]
            for p in people:
                if len(B) == N or (p[0] < p[1] and len(A) < N):
                    # A is cheaper
                    A.append(p[0])
                else:
                    B.append(p[1])
        return sum(A) + sum(B)


def testTwoCityScheduler(solution, input, output):
    if not output == solution.twoCitySchedCost(input):
        print "Your answer: ", solution.twoCitySchedCost(input)
        print "Expected Answer: ", output

if __name__ == '__main__':
    sol = Solution()
    testTwoCityScheduler(sol, [[10,20],[30,200],[400,50],[30,20]], 110)
    testTwoCityScheduler(sol, [[10,500],[30,200],[400,50],[30,20],[1000,999], [999,1000]], 2108)
