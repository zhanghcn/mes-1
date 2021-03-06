/****** 对象:  Table [dbo].[SettingList]    脚本日期: 04/22/2016 16:40:58 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[SettingList](
	[ID] [int] IDENTITY(1,1) NOT NULL,
	[ProductName] [varchar](50) COLLATE Chinese_PRC_CI_AS NOT NULL,
	[OrderName] [varchar](50) COLLATE Chinese_PRC_CI_AS NOT NULL,
	[Platform] [int] NOT NULL CONSTRAINT [DF__SettingLi__Platf__7F60ED59]  DEFAULT ((0)),
	[BTFT] [int] NOT NULL CONSTRAINT [DF__SettingLis__BTFT__08EA5793]  DEFAULT ((0)),
	[ResetFactory] [int] NOT NULL CONSTRAINT [DF__SettingLi__Reset__173876EA]  DEFAULT ((0)),
	[ScanPSN] [int] NULL,
	[WritePSNToPhone] [int] NULL,
	[PSNLength] [int] NULL,
	[CheckPSN] [int] NULL,
	[PSNCheckBit] [varchar](100) COLLATE Chinese_PRC_CI_AS NULL,
	[ScanNetCode] [int] NULL,
	[NetCodeLength] [int] NULL,
	[NetCodeHeader] [varchar](100) COLLATE Chinese_PRC_CI_AS NULL,
	[CheckVersion] [int] NOT NULL CONSTRAINT [DF__SettingLi__Check__1FCDBCEB]  DEFAULT ((0)),
	[VersionCode] [varchar](100) COLLATE Chinese_PRC_CI_AS NULL,
	[CheckBoardVersion] [int] NOT NULL CONSTRAINT [DF__SettingLi__Check__21B6055D]  DEFAULT ((0)),
	[BoardVersionCode] [varchar](100) COLLATE Chinese_PRC_CI_AS NULL,
	[ColorBoxLowWeigh] [float] NOT NULL,
	[ColorBoxHighWeigh] [float] NOT NULL,
	[CartonBoxLowWeigh] [float] NOT NULL,
	[CartonBoxHighWeigh] [float] NOT NULL,
	[iReserved1] [int] NULL,
	[iReserved2] [int] NULL,
	[iReserved3] [int] NULL,
	[iReserved4] [int] NULL,
	[iReserved5] [int] NULL,
	[fReserved1] [float] NULL,
	[fReserved2] [float] NULL,
	[fReserved3] [float] NULL,
	[fReserved4] [float] NULL,
	[fReserved5] [float] NULL,
	[csReserved1] [varchar](50) COLLATE Chinese_PRC_CI_AS NULL,
	[csReserved2] [varchar](50) COLLATE Chinese_PRC_CI_AS NULL,
	[csReserved3] [varchar](50) COLLATE Chinese_PRC_CI_AS NULL,
	[csReserved4] [varchar](50) COLLATE Chinese_PRC_CI_AS NULL,
	[csReserved5] [varchar](50) COLLATE Chinese_PRC_CI_AS NULL,
	[Enable] [int] NOT NULL,
	[datetime] [datetime] NULL CONSTRAINT [DF__SettingLi__datet__31EC6D26]  DEFAULT (getdate()),
 CONSTRAINT [PK__SettingList__7E6CC920] PRIMARY KEY CLUSTERED 
(
	[ID] ASC
)WITH (IGNORE_DUP_KEY = OFF) ON [PRIMARY]
) ON [PRIMARY]

GO
SET ANSI_PADDING OFF