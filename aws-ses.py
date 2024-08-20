import smtplib
import os

# Retrieve AWS credentials from environment variables
access_key_id = os.environ.get('AWS_ACCESS_KEY_ID')
secret_access_key = os.environ.get('AWS_SECRET_ACCESS_KEY')

if not access_key_id or not secret_access_key:
    print("AWS credentials not found in environment variables.")
#    exiti()

# Update the following credentials as per your AWS SES account
user = "AKIAWOHNUFMEGOGWADM6"
pw   = "BMl7aIHx0kCQHsChxEVUe18HUioa2fYNBCDVIyIB78PJ"
host = 'email-smtp.us-east-2.amazonaws.com'
port = 465
me   = 'Reporte de ventas <no-reply@sirdona.cl>'
you  = ('dev@mobiquos.cl','infraestructura@mobiquos.cl')  # Use a tuple if sending to multiple recipients
body = 'Test from AWS SES'
msg  = ("From: %s\r\nTo: %s\r\n\r\n" % (me, ", ".join(you)))
msg += body

try:
    # Establish connection with the SMTP server
    s = smtplib.SMTP_SSL(host, port)
    s.set_debuglevel(1)  # Enable debugging output
    # Login to the SMTP server
    s.login(user, pw)
    # Send the email
    s.sendmail(me, you, msg)
    print("Email sent successfully!")
except Exception as e:
    print("An error occurred while sending the email:", str(e))
finally:
    # Close the connection
    if 's' in locals():
        s.quit()

