ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
	ListNode *pSum = NULL, *ptr = NULL;
	int n = 0, c = 0, nVal1 = 0, nVal2 = 0;

	if (l1 == NULL)
		return l2;
	else if (l2 == NULL)
	    return l1;
		
	while (l1 || l2)
	{
		nVal1 = (l1 == NULL) ? 0 : l1->val;
		nVal2 = (l2 == NULL) ? 0 : l2->val;
		n = nVal1 + nVal2 + c;
		
		/*
		if (n >= 10)
		{
			n -= 10;
			c = 1;
		}
		else
			c = 0;
		*/

		c = n / 10;
		n %= 10;
		
		ListNode *p = new ListNode(n);
		(pSum == NULL) ? (pSum = ptr = p) : (ptr = ptr->next = p);
		l1 = (l1 == NULL) ? NULL : l1->next;
		l2 = (l2 == NULL) ? NULL : l2->next;
	}
	
	if (c == 1)
	{
		ListNode *p = new ListNode(1);
		ptr->next = p;
	}
	
	return pSum;
}
