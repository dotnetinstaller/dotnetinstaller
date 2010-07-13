<!-- tiscript, hyper text preprocessor mode  -->
<% var num_items = 10000; %>
<html>
<body>
  Here is &lt;table&gt; with <% =num_items %> rows.
 <table border=1 width=100%>
  <% for(var i = 0; i < num_items; ++i ) { %>
  <tr>
  <td >row #<% =i %></td>
  <td >sample text 1</td>
  <td >sample text 2 and text 3</td>
  </tr>
<% } %>
  </select>
</body>
</html>