if exists (select * from sysobjects where id = object_id(N'[dbo].[SessionVariables]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[SessionVariables]
GO
if exists (select * from sysobjects where id = object_id(N'[dbo].[SessionReferences]') and OBJECTPROPERTY(id, N'IsUserTable') = 1)
drop table [dbo].[SessionReferences]
GO
CREATE TABLE [dbo].[SessionReferences] (
	[SessionID] [varchar] (128) NOT NULL PRIMARY KEY NONCLUSTERED,
	[LastAccess] [datetime] NOT NULL ,
	[RefCount] [int] NULL ,
	[TimeoutMs] [int] NULL
)
GO

CREATE TABLE [dbo].[SessionVariables] (
	[SessionID] [varchar] (128) NOT NULL ,
	[VariableName] [varchar] (50) NOT NULL ,
	[VariableValue] [binary] (1024) NOT NULL ,
	CONSTRAINT PK_SessionVariables PRIMARY KEY NONCLUSTERED 
	(
	SessionID,
	VariableName
	) , 
CONSTRAINT Fkey FOREIGN KEY (SessionID) REFERENCES SessionReferences )
GO