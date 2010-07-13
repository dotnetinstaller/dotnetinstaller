This sample uses "functional mixin" technique of HTMLayout embedding.
I beleive that this is right way to use HTMLayout in MFC as MFC does 
a lot of things "under the hood" of CWnd.

This way HTMLayout can be attached to any CWnd derived class. 