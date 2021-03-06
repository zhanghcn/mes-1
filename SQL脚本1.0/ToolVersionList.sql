/****** 对象:  Table [dbo].[ToolVersionList]    脚本日期: 04/22/2016 16:32:26 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[ToolVersionList](
	[ID] [int] IDENTITY(1,1) NOT NULL,
	[CreateProductTool] [varchar](50) COLLATE Chinese_PRC_CI_AS NOT NULL,
	[SNScanTool] [varchar](50) COLLATE Chinese_PRC_CI_AS NOT NULL,
	[WriteIMEITool] [varchar](50) COLLATE Chinese_PRC_CI_AS NOT NULL,
	[CheckIMEIS1Tool] [varchar](50) COLLATE Chinese_PRC_CI_AS NOT NULL,
	[ColorBoxTool] [varchar](50) COLLATE Chinese_PRC_CI_AS NOT NULL,
	[CheckIMEIS2Tool] [varchar](50) COLLATE Chinese_PRC_CI_AS NOT NULL,
	[ColorBoxWeighTool] [varchar](50) COLLATE Chinese_PRC_CI_AS NOT NULL,
	[CartonBoxTool] [varchar](50) COLLATE Chinese_PRC_CI_AS NOT NULL,
	[CartonBoxWeighTool] [varchar](50) COLLATE Chinese_PRC_CI_AS NOT NULL,
	[PalletTool] [varchar](50) COLLATE Chinese_PRC_CI_AS NOT NULL,
	[CheckOrderTool] [varchar](50) COLLATE Chinese_PRC_CI_AS NOT NULL,
	[ProductionDataQueryTool] [varchar](50) COLLATE Chinese_PRC_CI_AS NOT NULL,
	[ReworkTool] [varchar](50) COLLATE Chinese_PRC_CI_AS NOT NULL,
	[Enable] [int] NOT NULL,
	[datetime] [datetime] NULL CONSTRAINT [DF__ToolVersi__datet__5D2BD0E6]  DEFAULT (getdate()),
 CONSTRAINT [PK__ToolVersionList__5C37ACAD] PRIMARY KEY CLUSTERED 
(
	[ID] ASC
)WITH (IGNORE_DUP_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF