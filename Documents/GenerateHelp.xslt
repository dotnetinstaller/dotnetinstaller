<?xml version="1.0" encoding="UTF-8"?>
<?xmlspysamplexml H:\DATI\MyWorks\SetupProject\Document\ElementsHelp.xml?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
	<xsl:output method="html" version="1.0" encoding="UTF-8" indent="yes">
	</xsl:output>
	
	<xsl:template match="/">
		<html>
			<head>
				<title></title>
			</head>
			<body>
				<xsl:apply-templates></xsl:apply-templates>
			</body>
		</html>
	</xsl:template>

	<xsl:template match="elements">
		<xsl:apply-templates></xsl:apply-templates>
	</xsl:template>
		
	<xsl:template match="element">
		<table cellpadding="0" cellspacing="0" border="1">
			<tbody>
				<tr>
					<th  bgcolor="#ccccff" colspan="2"><xsl:value-of select="@name"></xsl:value-of></th>
				</tr>
				<tr>
					<td colspan="2"><xsl:value-of select="@description"></xsl:value-of></td>
				</tr>
				<tr>
					<td bgcolor="#ccccff" valign="top">ATTRIBUTES:</td>
					<td>
						<table cellpadding="0" cellspacing="0" border="1">
							<tbody>
								<xsl:apply-templates select="attribute"></xsl:apply-templates>
							</tbody>
						</table>
					</td>
				</tr>
				<tr>
					<td bgcolor="#ccccff" valign="top">CHILDREN:</td>
					<td>
						<table cellpadding="0" cellspacing="0" border="0">
							<tbody>
								<xsl:apply-templates select="subelement"></xsl:apply-templates>
							</tbody>
						</table>
					</td>
				</tr>
			</tbody>
		</table>
		<br></br>
	</xsl:template>
	
	<xsl:template match="attribute">
		<tr>
			<td><b><xsl:value-of select="@name"></xsl:value-of></b></td>
			<td><xsl:value-of select="@description"></xsl:value-of></td>
		</tr>
	</xsl:template>

	<xsl:template match="subelement">
		<tr>
			<td><b><xsl:value-of select="@name"></xsl:value-of></b></td>
		</tr>
	</xsl:template>
		
</xsl:stylesheet>
